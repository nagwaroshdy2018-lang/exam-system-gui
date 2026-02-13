#include "studentwindow.h"
#include "ui_studentwindow.h"
#include "examdata.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <algorithm>

StudentWindow::StudentWindow(int language, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentWindow),
    language(language),
    currentQuestionIndex(0),
    correctCount(0),
    timeRemaining(30)
{
    ui->setupUi(this);
    setWindowTitle("Exam System - Student");
    resize(1000, 750);
    
    setupPages();
    showLoginPage();
    
    // Setup timers
    examTimer = new QTimer(this);
    examTimer->setSingleShot(true);
    connect(examTimer, &QTimer::timeout, this, [this]() { finishExam(true); });
    
    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, &StudentWindow::updateTimer);
    
    // Setup button group for radio buttons
    answerGroup = new QButtonGroup(this);
    answerGroup->addButton(ui->optionA, 0);
    answerGroup->addButton(ui->optionB, 1);
    answerGroup->addButton(ui->optionC, 2);
    answerGroup->addButton(ui->optionD, 3);
    answerGroup->setExclusive(true);
    
    // Formal Styles
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
        QLineEdit {
            background-color: white;
            border: 1px solid #cccccc;
            border-radius: 4px;
            padding: 10px;
            color: #333333;
            font-size: 16px;
        }
        QLabel {
            color: #333333;
            font-size: 14px;
        }
        QLabel#timerLabel {
            font-size: 36px;
            font-weight: bold;
            color: #388e3c;
        }
        QRadioButton {
            color: #333333;
            font-size: 16px;
            padding: 10px;
            spacing: 10px;
        }
        QRadioButton::indicator {
            width: 20px;
            height: 20px;
            border-radius: 10px;
        }
        QProgressBar {
            border: none;
            border-radius: 4px;
            background-color: #e0e0e0;
            text-align: center;
            color: #333333;
        }
        QProgressBar::chunk {
            background-color: #1976d2;
            border-radius: 4px;
        }
    )");
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

QString StudentWindow::tr(const QString& key)
{
    if (language == 2) { // German
        if (key == "app_name") return "Pruefungssystem - Student";
        if (key == "login") return "Anmelden";
        if (key == "student_id") return "Studenten-ID:";
        if (key == "instructions") return "📖 Anweisungen";
        if (key == "time_limit") return "Zeitlimit: 30 Sekunden";
        if (key == "passing") return "Bestehensgrenze: 50%";
        if (key == "random") return "Fragen sind randomisiert";
        if (key == "good_luck") return "Viel Glueck!";
        if (key == "start") return "🚀 Pruefung starten";
        if (key == "question") return "Frage";
        if (key == "of") return "von";
        if (key == "submit") return "✓ Einreichen";
        if (key == "next") return "Weiter →";
        if (key == "results") return "Ergebnisse";
        if (key == "score") return "Punktzahl";
        if (key == "correct") return "Richtig";
        if (key == "pass") return "🎉 BESTANDEN!";
        if (key == "fail") return "❌ NICHT BESTANDEN";
        if (key == "time_up") return "⏰ Zeit abgelaufen!";
        if (key == "close") return "Schliessen";
        if (key == "invalid_id") return "Ungueltige ID!";
        if (key == "already_taken") return "Pruefung bereits abgelegt!";
        if (key == "not_found") return "Student nicht gefunden!";
    }
    // English
    if (key == "app_name") return "Exam System - Student";
    if (key == "login") return "Login";
    if (key == "student_id") return "Student ID:";
    if (key == "instructions") return "📖 Instructions";
    if (key == "time_limit") return "Time Limit: 30 seconds";
    if (key == "passing") return "Passing Score: 50%";
    if (key == "random") return "Questions are randomized";
    if (key == "good_luck") return "Good Luck!";
    if (key == "start") return "🚀 Start Exam";
    if (key == "question") return "Question";
    if (key == "of") return "of";
    if (key == "submit") return "✓ Submit";
    if (key == "next") return "Next →";
    if (key == "results") return "Results";
    if (key == "score") return "Score";
    if (key == "correct") return "Correct";
    if (key == "pass") return "🎉 PASS!";
    if (key == "fail") return "❌ FAIL";
    if (key == "time_up") return "⏰ Time Up!";
    if (key == "close") return "Close";
    if (key == "invalid_id") return "Invalid ID!";
    if (key == "already_taken") return "Exam already taken!";
    if (key == "not_found") return "Student not found!";
    return key;
}

void StudentWindow::setupPages()
{
    bool isGerman = (language == 2);
    
    // Login Page
    connect(ui->loginButton, &QPushButton::clicked, this, &StudentWindow::on_loginButton_clicked);
    ui->studentIdLabel->setText(isGerman ? "Studenten-ID:" : "Student ID:");
    ui->loginButton->setText(isGerman ? "Anmelden" : "Login");
    ui->loginTitle->setText(isGerman ? "Student Anmeldung" : "Student Login");
    ui->loginTitle->setStyleSheet("font-size: 28px; font-weight: bold; color: #1976d2;");
    
    // Instructions Page
    connect(ui->startExamButton, &QPushButton::clicked, this, &StudentWindow::on_startExamButton_clicked);
    ui->instructionsTitle->setText(isGerman ? "Anweisungen" : "Instructions");
    ui->instructionsTitle->setStyleSheet("font-size: 28px; font-weight: bold; color: #1976d2;");
    ui->timeLimitLabel->setText(isGerman ? "Zeitlimit: 30 Sekunden" : "Time Limit: 30 seconds");
    ui->passingLabel->setText(isGerman ? "Bestehensgrenze: 50%" : "Passing Score: 50%");
    ui->randomLabel->setText(isGerman ? "Fragen sind randomisiert" : "Questions are randomized");
    ui->goodLuckLabel->setText(isGerman ? "Viel Glueck!" : "Good Luck!");
    ui->startExamButton->setText(isGerman ? "Pruefung starten" : "Start Exam");
    
    // Exam Page
    connect(ui->submitButton, &QPushButton::clicked, this, &StudentWindow::on_submitButton_clicked);
    connect(ui->nextButton, &QPushButton::clicked, this, &StudentWindow::on_nextButton_clicked);
    ui->submitButton->setText(isGerman ? "Einreichen" : "Submit");
    ui->nextButton->setText(isGerman ? "Weiter" : "Next");
    ui->timerLabel->setObjectName("timerLabel");
    
    // Results Page
    ui->resultsTitle->setText(isGerman ? "Ergebnisse" : "Results");
    ui->resultsTitle->setStyleSheet("font-size: 32px; font-weight: bold; color: #333333;");
    ui->closeButton->setText(isGerman ? "Schliessen" : "Close");
    connect(ui->closeButton, &QPushButton::clicked, this, [this]() {
        emit finished();
        this->close();
    });
}

void StudentWindow::showLoginPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void StudentWindow::showInstructionsPage()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void StudentWindow::showExamPage()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void StudentWindow::showResultsPage()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void StudentWindow::showMessage(const QString& msg, bool isError)
{
    QString title;
    if (language == 2) {
        title = isError ? "Fehler" : "Info";
    } else {
        title = isError ? "Error" : "Info";
    }
    QMessageBox::information(this, title, msg);
}

void StudentWindow::on_loginButton_clicked()
{
    studentId = ui->studentIdEdit->text().trimmed();
    
    if (studentId.length() != 4) {
        QString msg = (language == 2) ? "Ungueltige ID! (4 Ziffern erforderlich)" : "Invalid ID! (4 digits required)";
        showMessage(msg, true);
        return;
    }
    
    if (!ExamData::instance().studentExists(studentId)) {
        QString msg = (language == 2) ? "Student nicht gefunden!" : "Student not found!";
        showMessage(msg, true);
        return;
    }
    
    if (ExamData::instance().hasTakenExam(studentId)) {
        QString msg = (language == 2) ? "Pruefung bereits abgelegt!" : "Exam already taken!";
        showMessage(msg, true);
        return;
    }
    
    questions = ExamData::instance().loadQuestions();
    if (questions.isEmpty()) {
        QString msg = (language == 2) ? "Keine Fragen verfuegbar!" : "No questions available!";
        showMessage(msg, true);
        return;
    }
    
    // Shuffle questions
    std::shuffle(questions.begin(), questions.end(), *QRandomGenerator::global());
    
    showInstructionsPage();
}

void StudentWindow::on_startExamButton_clicked()
{
    currentQuestionIndex = 0;
    correctCount = 0;
    timeRemaining = 30;
    
    // Start 30 second timer
    examTimer->start(30000);
    countdownTimer->start(1000); // Update every second
    
    loadCurrentQuestion();
    showExamPage();
}

void StudentWindow::loadCurrentQuestion()
{
    if (currentQuestionIndex >= questions.size()) {
        finishExam(false);
        return;
    }
    
    const Question& q = questions[currentQuestionIndex];
    
    // Update progress
    int progress = (currentQuestionIndex * 100) / questions.size();
    ui->progressBar->setValue(progress);
    
    // Update question info
    QString questionText = (language == 2) ? "Frage" : "Question";
    QString ofText = (language == 2) ? "von" : "of";
    ui->questionInfoLabel->setText(QString("%1 %2 %3 %4").arg(questionText)
        .arg(currentQuestionIndex + 1).arg(ofText).arg(questions.size()));
    
    // Update question text
    ui->questionTextEdit->setPlainText(QString::fromStdString(q.text));
    
    // Update radio buttons
    ui->optionA->setText("A) " + QString::fromStdString(q.options[0]));
    ui->optionB->setText("B) " + QString::fromStdString(q.options[1]));
    ui->optionC->setText("C) " + QString::fromStdString(q.options[2]));
    ui->optionD->setText("D) " + QString::fromStdString(q.options[3]));
    
    // Uncheck all
    ui->optionA->setChecked(false);
    ui->optionB->setChecked(false);
    ui->optionC->setChecked(false);
    ui->optionD->setChecked(false);
    
    // Show/hide buttons
    bool isLast = (currentQuestionIndex == questions.size() - 1);
    ui->submitButton->setVisible(isLast);
    ui->nextButton->setVisible(!isLast);
}

void StudentWindow::updateTimer()
{
    timeRemaining--;
    ui->timerLabel->setText(QString::number(timeRemaining));
    
    if (timeRemaining <= 10) {
        ui->timerLabel->setStyleSheet("font-size: 36px; font-weight: bold; color: #d32f2f;");
    } else {
        ui->timerLabel->setStyleSheet("font-size: 36px; font-weight: bold; color: #388e3c;");
    }
}

void StudentWindow::on_nextButton_clicked()
{
    // Check answer
    const Question& q = questions[currentQuestionIndex];
    char selected = '\0';
    
    if (ui->optionA->isChecked()) selected = 'A';
    else if (ui->optionB->isChecked()) selected = 'B';
    else if (ui->optionC->isChecked()) selected = 'C';
    else if (ui->optionD->isChecked()) selected = 'D';
    
    if (selected == q.correctAnswer) {
        correctCount++;
    }
    
    currentQuestionIndex++;
    loadCurrentQuestion();
}

void StudentWindow::on_submitButton_clicked()
{
    // Check answer
    const Question& q = questions[currentQuestionIndex];
    char selected = '\0';
    
    if (ui->optionA->isChecked()) selected = 'A';
    else if (ui->optionB->isChecked()) selected = 'B';
    else if (ui->optionC->isChecked()) selected = 'C';
    else if (ui->optionD->isChecked()) selected = 'D';
    
    if (selected == q.correctAnswer) {
        correctCount++;
    }
    
    finishExam(false);
}

void StudentWindow::finishExam(bool timeUp)
{
    examTimer->stop();
    countdownTimer->stop();
    
    int total = questions.size();
    int score = (correctCount * 100) / total;
    bool passed = score >= 50;
    
    // Save result
    QString status = passed ? "PASS" : "FAIL";
    ExamData::instance().saveResult(studentId, score, status, timeUp);
    
    // Show results
    ui->scoreLabel->setText(QString::number(score) + "%");
    ui->scoreLabel->setStyleSheet(QString("font-size: 72px; font-weight: bold; color: %1;")
        .arg(passed ? "#388e3c" : "#d32f2f"));
    
    QString passText = passed ? (language == 2 ? "BESTANDEN!" : "PASS!") : (language == 2 ? "NICHT BESTANDEN" : "FAIL");
    ui->statusLabel->setText(passText);
    ui->statusLabel->setStyleSheet(QString("font-size: 32px; font-weight: bold; color: %1;")
        .arg(passed ? "#388e3c" : "#d32f2f"));
    
    QString correctText = (language == 2) ? "Richtig" : "Correct";
    ui->detailsLabel->setText(QString("%1: %2 / %3").arg(correctText).arg(correctCount).arg(total));
    
    if (timeUp) {
        QString timeUpText = (language == 2) ? "Zeit abgelaufen!" : "Time up!";
        ui->timeUpLabel->setText(timeUpText);
        ui->timeUpLabel->setStyleSheet("font-size: 24px; color: #f57c00;");
    } else {
        ui->timeUpLabel->clear();
    }
    
    showResultsPage();
}
