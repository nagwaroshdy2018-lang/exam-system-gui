#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminwindow.h"
#include "studentwindow.h"
#include <QMessageBox>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Exam System");
    resize(900, 700);
    
    // Apply formal styling
    setStyleSheet(R"(
        QMainWindow {
            background-color: #f5f5f5;
        }
        QPushButton {
            border: none;
            border-radius: 8px;
            padding: 20px 40px;
            font-size: 18px;
            font-weight: bold;
            color: white;
            min-width: 250px;
            min-height: 80px;
        }
        QPushButton:hover {
            background-color: #1565c0;
        }
        QPushButton:pressed {
            background-color: #0d47a1;
        }
        QLabel {
            color: #333333;
            font-size: 32px;
            font-weight: bold;
        }
        QLabel#subtitleLabel {
            font-size: 18px;
            color: #666666;
        }
    )");
    
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::tr(const QString& key)
{
    if (selectedLanguage == 2) { // German
        if (key == "welcome") return "Willkommen!";
        if (key == "select_role") return "Waehlen Sie Ihre Rolle";
        if (key == "admin") return "👨‍💼 Administrator";
        if (key == "student") return "👨‍🎓 Student";
        if (key == "language") return "🌐 Sprache";
    }
    // English
    if (key == "welcome") return "Welcome!";
    if (key == "select_role") return "Select Your Role";
    if (key == "admin") return "👨‍💼 Admin";
    if (key == "student") return "👨‍🎓 Student";
    if (key == "language") return "🌐 Language";
    return key;
}

void MainWindow::updateUI()
{
    if (selectedLanguage == 2) { // German
        ui->titleLabel->setText("Willkommen!");
        ui->subtitleLabel->setText("Waehlen Sie Ihre Rolle");
        ui->adminButton->setText("Administrator");
        ui->studentButton->setText("Student");
        ui->languageButton->setText("Sprache (DE)");
    } else { // English
        ui->titleLabel->setText("Welcome!");
        ui->subtitleLabel->setText("Select Your Role");
        ui->adminButton->setText("Admin");
        ui->studentButton->setText("Student");
        ui->languageButton->setText("Language (EN)");
    }
    
    // Style buttons with formal colors
    ui->adminButton->setStyleSheet("background-color: #1976d2;");
    ui->studentButton->setStyleSheet("background-color: #388e3c;");
    ui->languageButton->setStyleSheet("background-color: #757575; font-size: 14px; min-height: 50px;");
}

void MainWindow::on_adminButton_clicked()
{
    if (selectedLanguage == 0) {
        selectedLanguage = 1; // Default to English
    }
    
    AdminWindow *adminWin = new AdminWindow(selectedLanguage, nullptr);
    adminWin->setAttribute(Qt::WA_DeleteOnClose);
    connect(adminWin, &AdminWindow::windowClosed, this, [this]() {
        this->show();
        this->raise();
        this->activateWindow();
    });
    adminWin->show();
    this->hide();
}

void MainWindow::on_studentButton_clicked()
{
    if (selectedLanguage == 0) {
        selectedLanguage = 1; // Default to English
    }
    
    StudentWindow *studentWin = new StudentWindow(selectedLanguage, nullptr);
    studentWin->setAttribute(Qt::WA_DeleteOnClose);
    connect(studentWin, &StudentWindow::finished, this, [this]() {
        this->show();
        this->raise();
        this->activateWindow();
    });
    studentWin->show();
    this->hide();
}

void MainWindow::on_languageButton_clicked()
{
    selectedLanguage = (selectedLanguage == 2) ? 1 : 2;
    updateUI();
}
