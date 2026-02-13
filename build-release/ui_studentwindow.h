/********************************************************************************
** Form generated from reading UI file 'studentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QVBoxLayout *loginLayout;
    QLabel *loginTitle;
    QSpacerItem *spacer1;
    QFormLayout *formLayout;
    QLabel *studentIdLabel;
    QLineEdit *studentIdEdit;
    QPushButton *loginButton;
    QSpacerItem *spacer2;
    QWidget *instructionsPage;
    QVBoxLayout *instrLayout;
    QLabel *instructionsTitle;
    QFrame *timeLimitFrame;
    QHBoxLayout *timeLayout;
    QLabel *timeLimitLabel;
    QFrame *passingFrame;
    QHBoxLayout *passingLayout;
    QLabel *passingLabel;
    QFrame *randomFrame;
    QHBoxLayout *randomLayout;
    QLabel *randomLabel;
    QSpacerItem *spacer3;
    QLabel *goodLuckLabel;
    QPushButton *startExamButton;
    QWidget *examPage;
    QVBoxLayout *examLayout;
    QHBoxLayout *topLayout;
    QLabel *questionInfoLabel;
    QSpacerItem *spacer4;
    QLabel *timerLabel;
    QProgressBar *progressBar;
    QTextEdit *questionTextEdit;
    QRadioButton *optionA;
    QRadioButton *optionB;
    QRadioButton *optionC;
    QRadioButton *optionD;
    QSpacerItem *spacer5;
    QPushButton *nextButton;
    QPushButton *submitButton;
    QWidget *resultsPage;
    QVBoxLayout *resultsLayout;
    QLabel *resultsTitle;
    QLabel *scoreLabel;
    QLabel *statusLabel;
    QLabel *detailsLabel;
    QLabel *timeUpLabel;
    QSpacerItem *spacer6;
    QPushButton *closeButton;

    void setupUi(QMainWindow *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName("StudentWindow");
        StudentWindow->resize(900, 700);
        centralwidget = new QWidget(StudentWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        loginLayout = new QVBoxLayout(loginPage);
        loginLayout->setObjectName("loginLayout");
        loginTitle = new QLabel(loginPage);
        loginTitle->setObjectName("loginTitle");

        loginLayout->addWidget(loginTitle, 0, Qt::AlignHCenter);

        spacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        loginLayout->addItem(spacer1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        studentIdLabel = new QLabel(loginPage);
        studentIdLabel->setObjectName("studentIdLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, studentIdLabel);

        studentIdEdit = new QLineEdit(loginPage);
        studentIdEdit->setObjectName("studentIdEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, studentIdEdit);


        loginLayout->addLayout(formLayout);

        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setMinimumHeight(50);

        loginLayout->addWidget(loginButton);

        spacer2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        loginLayout->addItem(spacer2);

        stackedWidget->addWidget(loginPage);
        instructionsPage = new QWidget();
        instructionsPage->setObjectName("instructionsPage");
        instrLayout = new QVBoxLayout(instructionsPage);
        instrLayout->setObjectName("instrLayout");
        instructionsTitle = new QLabel(instructionsPage);
        instructionsTitle->setObjectName("instructionsTitle");

        instrLayout->addWidget(instructionsTitle, 0, Qt::AlignHCenter);

        timeLimitFrame = new QFrame(instructionsPage);
        timeLimitFrame->setObjectName("timeLimitFrame");
        timeLayout = new QHBoxLayout(timeLimitFrame);
        timeLayout->setObjectName("timeLayout");
        timeLimitLabel = new QLabel(timeLimitFrame);
        timeLimitLabel->setObjectName("timeLimitLabel");

        timeLayout->addWidget(timeLimitLabel);


        instrLayout->addWidget(timeLimitFrame);

        passingFrame = new QFrame(instructionsPage);
        passingFrame->setObjectName("passingFrame");
        passingLayout = new QHBoxLayout(passingFrame);
        passingLayout->setObjectName("passingLayout");
        passingLabel = new QLabel(passingFrame);
        passingLabel->setObjectName("passingLabel");

        passingLayout->addWidget(passingLabel);


        instrLayout->addWidget(passingFrame);

        randomFrame = new QFrame(instructionsPage);
        randomFrame->setObjectName("randomFrame");
        randomLayout = new QHBoxLayout(randomFrame);
        randomLayout->setObjectName("randomLayout");
        randomLabel = new QLabel(randomFrame);
        randomLabel->setObjectName("randomLabel");

        randomLayout->addWidget(randomLabel);


        instrLayout->addWidget(randomFrame);

        spacer3 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        instrLayout->addItem(spacer3);

        goodLuckLabel = new QLabel(instructionsPage);
        goodLuckLabel->setObjectName("goodLuckLabel");

        instrLayout->addWidget(goodLuckLabel, 0, Qt::AlignHCenter);

        startExamButton = new QPushButton(instructionsPage);
        startExamButton->setObjectName("startExamButton");
        startExamButton->setMinimumHeight(60);

        instrLayout->addWidget(startExamButton);

        stackedWidget->addWidget(instructionsPage);
        examPage = new QWidget();
        examPage->setObjectName("examPage");
        examLayout = new QVBoxLayout(examPage);
        examLayout->setObjectName("examLayout");
        topLayout = new QHBoxLayout();
        topLayout->setObjectName("topLayout");
        questionInfoLabel = new QLabel(examPage);
        questionInfoLabel->setObjectName("questionInfoLabel");

        topLayout->addWidget(questionInfoLabel);

        spacer4 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topLayout->addItem(spacer4);

        timerLabel = new QLabel(examPage);
        timerLabel->setObjectName("timerLabel");

        topLayout->addWidget(timerLabel);


        examLayout->addLayout(topLayout);

        progressBar = new QProgressBar(examPage);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);
        progressBar->setMaximumHeight(20);

        examLayout->addWidget(progressBar);

        questionTextEdit = new QTextEdit(examPage);
        questionTextEdit->setObjectName("questionTextEdit");
        questionTextEdit->setReadOnly(true);
        questionTextEdit->setMaximumHeight(120);

        examLayout->addWidget(questionTextEdit);

        optionA = new QRadioButton(examPage);
        optionA->setObjectName("optionA");

        examLayout->addWidget(optionA);

        optionB = new QRadioButton(examPage);
        optionB->setObjectName("optionB");

        examLayout->addWidget(optionB);

        optionC = new QRadioButton(examPage);
        optionC->setObjectName("optionC");

        examLayout->addWidget(optionC);

        optionD = new QRadioButton(examPage);
        optionD->setObjectName("optionD");

        examLayout->addWidget(optionD);

        spacer5 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        examLayout->addItem(spacer5);

        nextButton = new QPushButton(examPage);
        nextButton->setObjectName("nextButton");
        nextButton->setMinimumHeight(50);

        examLayout->addWidget(nextButton);

        submitButton = new QPushButton(examPage);
        submitButton->setObjectName("submitButton");
        submitButton->setMinimumHeight(50);

        examLayout->addWidget(submitButton);

        stackedWidget->addWidget(examPage);
        resultsPage = new QWidget();
        resultsPage->setObjectName("resultsPage");
        resultsLayout = new QVBoxLayout(resultsPage);
        resultsLayout->setObjectName("resultsLayout");
        resultsTitle = new QLabel(resultsPage);
        resultsTitle->setObjectName("resultsTitle");

        resultsLayout->addWidget(resultsTitle, 0, Qt::AlignHCenter);

        scoreLabel = new QLabel(resultsPage);
        scoreLabel->setObjectName("scoreLabel");

        resultsLayout->addWidget(scoreLabel, 0, Qt::AlignHCenter);

        statusLabel = new QLabel(resultsPage);
        statusLabel->setObjectName("statusLabel");

        resultsLayout->addWidget(statusLabel, 0, Qt::AlignHCenter);

        detailsLabel = new QLabel(resultsPage);
        detailsLabel->setObjectName("detailsLabel");

        resultsLayout->addWidget(detailsLabel, 0, Qt::AlignHCenter);

        timeUpLabel = new QLabel(resultsPage);
        timeUpLabel->setObjectName("timeUpLabel");

        resultsLayout->addWidget(timeUpLabel, 0, Qt::AlignHCenter);

        spacer6 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        resultsLayout->addItem(spacer6);

        closeButton = new QPushButton(resultsPage);
        closeButton->setObjectName("closeButton");
        closeButton->setMinimumHeight(50);

        resultsLayout->addWidget(closeButton);

        stackedWidget->addWidget(resultsPage);

        verticalLayout->addWidget(stackedWidget);

        StudentWindow->setCentralWidget(centralwidget);

        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StudentWindow)
    {
        loginTitle->setText(QCoreApplication::translate("StudentWindow", "Student Login", nullptr));
        studentIdLabel->setText(QCoreApplication::translate("StudentWindow", "Student ID:", nullptr));
        loginButton->setText(QCoreApplication::translate("StudentWindow", "Login", nullptr));
        instructionsTitle->setText(QCoreApplication::translate("StudentWindow", "Instructions", nullptr));
        timeLimitFrame->setStyleSheet(QCoreApplication::translate("StudentWindow", "background-color: #e3f2fd; border: 2px solid #1976d2; border-radius: 10px; padding: 15px;", nullptr));
        timeLimitLabel->setText(QCoreApplication::translate("StudentWindow", "Time Limit: 30 seconds", nullptr));
        timeLimitLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 18px; color: #1565c0; font-weight: bold; background: transparent; border: none;", nullptr));
        passingFrame->setStyleSheet(QCoreApplication::translate("StudentWindow", "background-color: #e8f5e9; border: 2px solid #388e3c; border-radius: 10px; padding: 15px;", nullptr));
        passingLabel->setText(QCoreApplication::translate("StudentWindow", "Passing Score: 50%", nullptr));
        passingLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 18px; color: #2e7d32; font-weight: bold; background: transparent; border: none;", nullptr));
        randomFrame->setStyleSheet(QCoreApplication::translate("StudentWindow", "background-color: #fff3e0; border: 2px solid #f57c00; border-radius: 10px; padding: 15px;", nullptr));
        randomLabel->setText(QCoreApplication::translate("StudentWindow", "Questions are randomized", nullptr));
        randomLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 18px; color: #e65100; font-weight: bold; background: transparent; border: none;", nullptr));
        goodLuckLabel->setText(QCoreApplication::translate("StudentWindow", "Good Luck!", nullptr));
        goodLuckLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 24px; color: #27ae60; font-weight: bold;", nullptr));
        startExamButton->setText(QCoreApplication::translate("StudentWindow", "Start Exam", nullptr));
        questionInfoLabel->setText(QCoreApplication::translate("StudentWindow", "Question 1 of 10", nullptr));
        questionInfoLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 16px; color: #a0a0a0;", nullptr));
        timerLabel->setText(QCoreApplication::translate("StudentWindow", "30", nullptr));
        timerLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 36px; font-weight: bold; color: #27ae60;", nullptr));
        questionTextEdit->setStyleSheet(QCoreApplication::translate("StudentWindow", "background-color: #e3f2fd; color: #1565c0; font-size: 18px; font-weight: bold; padding: 15px; border: 2px solid #1976d2; border-radius: 8px;", nullptr));
        optionA->setText(QCoreApplication::translate("StudentWindow", "Option A", nullptr));
        optionA->setStyleSheet(QCoreApplication::translate("StudentWindow", "QRadioButton { font-size: 16px; padding: 10px; background-color: white; border: 2px solid #cccccc; border-radius: 8px; } QRadioButton::indicator { width: 20px; height: 20px; } QRadioButton:checked { background-color: #e3f2fd; border-color: #1976d2; }", nullptr));
        optionB->setText(QCoreApplication::translate("StudentWindow", "Option B", nullptr));
        optionB->setStyleSheet(QCoreApplication::translate("StudentWindow", "QRadioButton { font-size: 16px; padding: 10px; background-color: white; border: 2px solid #cccccc; border-radius: 8px; } QRadioButton::indicator { width: 20px; height: 20px; } QRadioButton:checked { background-color: #e3f2fd; border-color: #1976d2; }", nullptr));
        optionC->setText(QCoreApplication::translate("StudentWindow", "Option C", nullptr));
        optionC->setStyleSheet(QCoreApplication::translate("StudentWindow", "QRadioButton { font-size: 16px; padding: 10px; background-color: white; border: 2px solid #cccccc; border-radius: 8px; } QRadioButton::indicator { width: 20px; height: 20px; } QRadioButton:checked { background-color: #e3f2fd; border-color: #1976d2; }", nullptr));
        optionD->setText(QCoreApplication::translate("StudentWindow", "Option D", nullptr));
        optionD->setStyleSheet(QCoreApplication::translate("StudentWindow", "QRadioButton { font-size: 16px; padding: 10px; background-color: white; border: 2px solid #cccccc; border-radius: 8px; } QRadioButton::indicator { width: 20px; height: 20px; } QRadioButton:checked { background-color: #e3f2fd; border-color: #1976d2; }", nullptr));
        nextButton->setText(QCoreApplication::translate("StudentWindow", "Next \342\206\222", nullptr));
        submitButton->setText(QCoreApplication::translate("StudentWindow", "Submit", nullptr));
        resultsTitle->setText(QCoreApplication::translate("StudentWindow", "Results", nullptr));
        scoreLabel->setText(QCoreApplication::translate("StudentWindow", "80%", nullptr));
        scoreLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 72px; font-weight: bold; color: #27ae60;", nullptr));
        statusLabel->setText(QCoreApplication::translate("StudentWindow", "PASS!", nullptr));
        statusLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 32px; font-weight: bold; color: #27ae60;", nullptr));
        detailsLabel->setText(QCoreApplication::translate("StudentWindow", "Correct: 4 / 5", nullptr));
        detailsLabel->setStyleSheet(QCoreApplication::translate("StudentWindow", "font-size: 18px; color: #a0a0a0;", nullptr));
        timeUpLabel->setText(QString());
        closeButton->setText(QCoreApplication::translate("StudentWindow", "Close", nullptr));
        (void)StudentWindow;
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
