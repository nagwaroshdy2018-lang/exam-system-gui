#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "examdata.h"
#include <QMessageBox>
#include <QInputDialog>

AdminWindow::AdminWindow(int language, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow),
    language(language)
{
    ui->setupUi(this);
    setWindowTitle("Exam System - Admin");
    resize(1000, 750);
    
    setupPages();
    showLoginPage();
    
    // Apply formal styles
    setStyleSheet(R"(
        QMainWindow {
            background-color: #f5f5f5;
        }
        QWidget {
            color: #333333;
            font-family: 'Segoe UI', Arial;
        }
        QPushButton {
            border: none;
            border-radius: 6px;
            padding: 15px 30px;
            font-size: 16px;
            font-weight: bold;
            color: white;
            background-color: #1976d2;
        }
        QPushButton:hover {
            background-color: #1565c0;
        }
        QPushButton:pressed {
            background-color: #0d47a1;
        }
        QLineEdit, QTextEdit, QComboBox {
            background-color: white;
            border: 1px solid #cccccc;
            border-radius: 4px;
            padding: 10px;
            color: #333333;
            font-size: 14px;
        }
        QLineEdit:focus, QTextEdit:focus, QComboBox:focus {
            border-color: #1976d2;
        }
        QLabel {
            color: #333333;
            font-size: 14px;
            font-weight: bold;
        }
        QListWidget {
            background-color: white;
            border: 1px solid #cccccc;
            border-radius: 4px;
            color: #333333;
            padding: 10px;
        }
        QListWidget::item {
            padding: 10px;
            border-bottom: 1px solid #eeeeee;
        }
        QListWidget::item:selected {
            background-color: #1976d2;
            color: white;
        }
    )");
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

QString AdminWindow::tr(const QString& key)
{
    if (language == 2) { // German
        if (key == "app_name") return "Pruefungssystem - Admin";
        if (key == "login") return "Anmelden";
        if (key == "username") return "Benutzername:";
        if (key == "password") return "Passwort:";
        if (key == "menu") return "Admin Menue";
        if (key == "add_q") return "➕ Frage hinzufuegen";
        if (key == "view_q") return "📋 Fragen anzeigen";
        if (key == "delete_q") return "🗑️ Frage loeschen";
        if (key == "logout") return "🚪 Abmelden";
        if (key == "question_id") return "Fragen-ID:";
        if (key == "question_text") return "Fragetext:";
        if (key == "option_a") return "Option A:";
        if (key == "option_b") return "Option B:";
        if (key == "option_c") return "Option C:";
        if (key == "option_d") return "Option D:";
        if (key == "correct_answer") return "Richtige Antwort:";
        if (key == "save") return "💾 Speichern";
        if (key == "cancel") return "❌ Abbrechen";
        if (key == "back") return "← Zurueck";
        if (key == "invalid") return "Ungueltige Anmeldedaten!";
        if (key == "saved") return "Frage gespeichert!";
        if (key == "deleted") return "Frage geloescht!";
    }
    // English
    if (key == "app_name") return "Exam System - Admin";
    if (key == "login") return "Login";
    if (key == "username") return "Username:";
    if (key == "password") return "Password:";
    if (key == "menu") return "Admin Menu";
    if (key == "add_q") return "➕ Add Question";
    if (key == "view_q") return "📋 View Questions";
    if (key == "delete_q") return "🗑️ Delete Question";
    if (key == "logout") return "🚪 Logout";
    if (key == "question_id") return "Question ID:";
    if (key == "question_text") return "Question Text:";
    if (key == "option_a") return "Option A:";
    if (key == "option_b") return "Option B:";
    if (key == "option_c") return "Option C:";
    if (key == "option_d") return "Option D:";
    if (key == "correct_answer") return "Correct Answer:";
    if (key == "save") return "💾 Save";
    if (key == "cancel") return "❌ Cancel";
    if (key == "back") return "← Back";
    if (key == "invalid") return "Invalid credentials!";
    if (key == "saved") return "Question saved!";
    if (key == "deleted") return "Question deleted!";
    return key;
}

void AdminWindow::setupPages()
{
    bool isGerman = (language == 2);
    
    // Login Page
    connect(ui->loginButton, &QPushButton::clicked, this, &AdminWindow::on_loginButton_clicked);
    ui->usernameLabel->setText(isGerman ? "Benutzername:" : "Username:");
    ui->passwordLabel->setText(isGerman ? "Passwort:" : "Password:");
    ui->loginButton->setText(isGerman ? "Anmelden" : "Login");
    ui->loginTitle->setText(isGerman ? "Admin Anmeldung" : "Admin Login");
    ui->loginTitle->setStyleSheet("font-size: 32px; font-weight: bold; color: #1976d2; margin-bottom: 20px;");
    
    // Make login button visible with explicit style
    ui->loginButton->setStyleSheet("background-color: #1976d2; color: white; font-weight: bold; font-size: 16px; padding: 15px;");
    
    // Menu Page
    connect(ui->addQuestionButton, &QPushButton::clicked, this, &AdminWindow::on_addQuestionButton_clicked);
    connect(ui->viewQuestionsButton, &QPushButton::clicked, this, &AdminWindow::on_viewQuestionsButton_clicked);
    connect(ui->updateQuestionButton, &QPushButton::clicked, this, &AdminWindow::on_updateQuestionButton_clicked);
    connect(ui->deleteQuestionButton, &QPushButton::clicked, this, &AdminWindow::on_deleteQuestionButton_clicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &AdminWindow::on_logoutButton_clicked);
    
    ui->menuTitle->setText(isGerman ? "Admin Menue" : "Admin Menu");
    ui->addQuestionButton->setText(isGerman ? "Frage hinzufuegen" : "Add Question");
    ui->viewQuestionsButton->setText(isGerman ? "Fragen anzeigen" : "View Questions");
    ui->updateQuestionButton->setText(isGerman ? "Frage bearbeiten" : "Update Question");
    ui->deleteQuestionButton->setText(isGerman ? "Frage loeschen" : "Delete Question");
    ui->logoutButton->setText(isGerman ? "Abmelden" : "Logout");
    
    // Style menu buttons with different colors
    ui->addQuestionButton->setStyleSheet("background-color: #1976d2; color: white; font-weight: bold;");
    ui->viewQuestionsButton->setStyleSheet("background-color: #388e3c; color: white; font-weight: bold;");
    ui->updateQuestionButton->setStyleSheet("background-color: #f57c00; color: white; font-weight: bold;");
    ui->deleteQuestionButton->setStyleSheet("background-color: #d32f2f; color: white; font-weight: bold;");
    ui->logoutButton->setStyleSheet("background-color: #757575; color: white; font-weight: bold;");
    
    // Add Question Page
    connect(ui->saveQuestionButton, &QPushButton::clicked, this, &AdminWindow::on_saveQuestionButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &AdminWindow::on_cancelButton_clicked);
    
    ui->addTitle->setText(isGerman ? "Frage hinzufuegen" : "Add Question");
    ui->idLabel->setText(isGerman ? "Fragen-ID:" : "Question ID:");
    ui->textLabel->setText(isGerman ? "Fragetext:" : "Question Text:");
    ui->optALabel->setText("Option A:");
    ui->optBLabel->setText("Option B:");
    ui->optCLabel->setText("Option C:");
    ui->optDLabel->setText("Option D:");
    ui->answerLabel->setText(isGerman ? "Richtige Antwort:" : "Correct Answer:");
    ui->saveQuestionButton->setText(isGerman ? "Speichern" : "Save");
    ui->cancelButton->setText(isGerman ? "Abbrechen" : "Cancel");
    
    ui->answerCombo->clear();
    ui->answerCombo->addItem("A");
    ui->answerCombo->addItem("B");
    ui->answerCombo->addItem("C");
    ui->answerCombo->addItem("D");
    
    // View Questions Page
    connect(ui->backToMenuButton, &QPushButton::clicked, this, &AdminWindow::on_backToMenuButton_clicked);
    ui->viewTitle->setText(isGerman ? "Fragen anzeigen" : "View Questions");
    ui->backToMenuButton->setText(isGerman ? "Zurueck" : "Back");
    
    // Style the accent bars - formal blue
    QString accentStyle = "background-color: #1976d2;";
}

void AdminWindow::showLoginPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AdminWindow::showMenuPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AdminWindow::showAddQuestionPage()
{
    ui->stackedWidget->setCurrentIndex(2);
    // Reset title to "Add Question"
    bool isGerman = (language == 2);
    ui->addTitle->setText(isGerman ? "Frage hinzufuegen" : "Add Question");
    // Re-enable ID field (it gets disabled during update)
    ui->idEdit->setEnabled(true);
    // Clear fields
    ui->idEdit->clear();
    ui->textEdit->clear();
    ui->optAEdit->clear();
    ui->optBEdit->clear();
    ui->optCEdit->clear();
    ui->optDEdit->clear();
    ui->answerCombo->setCurrentIndex(0);
}

void AdminWindow::showViewQuestionsPage()
{
    loadQuestionsList();
    ui->stackedWidget->setCurrentIndex(3);
}

void AdminWindow::loadQuestionsList()
{
    ui->questionsList->clear();
    questions = ExamData::instance().loadQuestions();
    
    for (const Question& q : questions) {
        QString item = QString("ID %1: %2 [Answer: %3]")
                           .arg(q.id)
                           .arg(QString::fromStdString(q.text))
                           .arg(QChar(q.correctAnswer));
        ui->questionsList->addItem(item);
    }
    
    ui->countLabel->setText(QString("Total: %1 questions").arg(questions.size()));
}

void AdminWindow::showMessage(const QString& msg, bool isError)
{
    QString title = isError ? "Error" : "Success";
    if (language == 2) {
        title = isError ? "Fehler" : "Erfolg";
    }
    QMessageBox::information(this, title, msg);
}

void AdminWindow::on_loginButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    
    if (username == "admin" && password == "admin") {
        isLoggedIn = true;
        ui->usernameEdit->clear();
        ui->passwordEdit->clear();
        showMenuPage();
    } else {
        QString msg = (language == 2) ? "Ungueltige Anmeldedaten!" : "Invalid credentials!";
        showMessage(msg, true);
    }
}

void AdminWindow::on_addQuestionButton_clicked()
{
    showAddQuestionPage();
}

void AdminWindow::on_viewQuestionsButton_clicked()
{
    showViewQuestionsPage();
}

void AdminWindow::on_updateQuestionButton_clicked()
{
    bool ok;
    int id = QInputDialog::getInt(this, 
        language == 2 ? "Frage bearbeiten" : "Update Question",
        language == 2 ? "Fragen-ID eingeben:" : "Enter Question ID:",
        1, 1, 9999, 1, &ok);
    
    if (!ok) return;
    
    // Load the question
    QVector<Question> questions = ExamData::instance().loadQuestions();
    Question foundQ;
    bool found = false;
    for (const Question& q : questions) {
        if (q.id == id) {
            foundQ = q;
            found = true;
            break;
        }
    }
    
    if (!found) {
        QString msg = (language == 2) ? "Frage nicht gefunden!" : "Question not found!";
        showMessage(msg, true);
        return;
    }
    
    // Set title first
    ui->addTitle->setText(language == 2 ? "Frage bearbeiten" : "Update Question");
    
    // Show page (this clears fields, so we fill AFTER)
    showAddQuestionPage();
    
    // NOW fill the form with existing data (after clear)
    ui->idEdit->setText(QString::number(foundQ.id));
    ui->idEdit->setEnabled(false); // Can't change ID
    ui->textEdit->setPlainText(QString::fromStdString(foundQ.text));
    ui->optAEdit->setText(QString::fromStdString(foundQ.options[0]));
    ui->optBEdit->setText(QString::fromStdString(foundQ.options[1]));
    ui->optCEdit->setText(QString::fromStdString(foundQ.options[2]));
    ui->optDEdit->setText(QString::fromStdString(foundQ.options[3]));
    
    int ansIndex = foundQ.correctAnswer - 'A';
    if (ansIndex >= 0 && ansIndex <= 3) {
        ui->answerCombo->setCurrentIndex(ansIndex);
    }
}

void AdminWindow::on_deleteQuestionButton_clicked()
{
    bool ok;
    int id = QInputDialog::getInt(this, 
        language == 2 ? "Frage loeschen" : "Delete Question",
        language == 2 ? "Fragen-ID eingeben:" : "Enter Question ID:",
        1, 1, 9999, 1, &ok);
    if (ok) {
        if (ExamData::instance().deleteQuestion(id)) {
            QString msg = (language == 2) ? "Frage geloescht!" : "Question deleted!";
            showMessage(msg, false);
        } else {
            QString msg = (language == 2) ? "Frage nicht gefunden!" : "Question not found!";
            showMessage(msg, true);
        }
    }
}

void AdminWindow::on_logoutButton_clicked()
{
    isLoggedIn = false;
    showLoginPage();
    emit windowClosed();
    this->close();
}

void AdminWindow::on_saveQuestionButton_clicked()
{
    int id = ui->idEdit->text().toInt();
    QString text = ui->textEdit->toPlainText();
    QString optA = ui->optAEdit->text();
    QString optB = ui->optBEdit->text();
    QString optC = ui->optCEdit->text();
    QString optD = ui->optDEdit->text();
    QChar answer = ui->answerCombo->currentText()[0];
    
    if (id <= 0 || text.isEmpty() || optA.isEmpty() || optB.isEmpty() || 
        optC.isEmpty() || optD.isEmpty()) {
        QString msg = (language == 2) ? "Bitte alle Felder ausfuellen!" : "Please fill all fields!";
        showMessage(msg, true);
        return;
    }
    
    QString opts[4] = {optA, optB, optC, optD};
    Question q(id, text, opts, answer);
    
    // Check if we're updating or adding
    bool isUpdate = ui->addTitle->text().contains("Update") || ui->addTitle->text().contains("bearbeiten");
    
    if (!isUpdate && ExamData::instance().questionExists(id)) {
        QString msg = (language == 2) ? "Fragen-ID existiert bereits!" : "Question ID already exists!";
        showMessage(msg, true);
        return;
    }
    
    bool success;
    if (isUpdate) {
        success = ExamData::instance().updateQuestion(q);
    } else {
        success = ExamData::instance().saveQuestion(q);
    }
    
    if (success) {
        QString msg = isUpdate ? 
            (language == 2 ? "Frage aktualisiert!" : "Question updated!") :
            (language == 2 ? "Frage gespeichert!" : "Question saved!");
        showMessage(msg, false);
        ui->idEdit->setEnabled(true); // Re-enable ID field
        showMenuPage();
    } else {
        QString msg = (language == 2) ? "Speichern fehlgeschlagen!" : "Failed to save!";
        showMessage(msg, true);
    }
}

void AdminWindow::on_cancelButton_clicked()
{
    showMenuPage();
}

void AdminWindow::on_backToMenuButton_clicked()
{
    showMenuPage();
}
