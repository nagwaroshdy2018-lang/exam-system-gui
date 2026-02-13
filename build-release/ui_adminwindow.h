/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
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
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QSpacerItem *spacer2;
    QWidget *menuPage;
    QVBoxLayout *menuLayout;
    QLabel *menuTitle;
    QPushButton *addQuestionButton;
    QPushButton *viewQuestionsButton;
    QPushButton *updateQuestionButton;
    QPushButton *deleteQuestionButton;
    QSpacerItem *spacer3;
    QPushButton *logoutButton;
    QWidget *addPage;
    QVBoxLayout *addLayout;
    QLabel *addTitle;
    QFormLayout *addForm;
    QLabel *idLabel;
    QLineEdit *idEdit;
    QLabel *textLabel;
    QTextEdit *textEdit;
    QLabel *optALabel;
    QLineEdit *optAEdit;
    QLabel *optBLabel;
    QLineEdit *optBEdit;
    QLabel *optCLabel;
    QLineEdit *optCEdit;
    QLabel *optDLabel;
    QLineEdit *optDEdit;
    QLabel *answerLabel;
    QComboBox *answerCombo;
    QHBoxLayout *buttonLayout;
    QPushButton *saveQuestionButton;
    QPushButton *cancelButton;
    QWidget *viewPage;
    QVBoxLayout *viewLayout;
    QLabel *viewTitle;
    QLabel *countLabel;
    QListWidget *questionsList;
    QPushButton *backToMenuButton;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(900, 700);
        centralwidget = new QWidget(AdminWindow);
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
        usernameLabel = new QLabel(loginPage);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, usernameLabel);

        usernameEdit = new QLineEdit(loginPage);
        usernameEdit->setObjectName("usernameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, usernameEdit);

        passwordLabel = new QLabel(loginPage);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, passwordLabel);

        passwordEdit = new QLineEdit(loginPage);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordEdit);


        loginLayout->addLayout(formLayout);

        loginButton = new QPushButton(loginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setMinimumHeight(50);

        loginLayout->addWidget(loginButton);

        spacer2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        loginLayout->addItem(spacer2);

        stackedWidget->addWidget(loginPage);
        menuPage = new QWidget();
        menuPage->setObjectName("menuPage");
        menuLayout = new QVBoxLayout(menuPage);
        menuLayout->setObjectName("menuLayout");
        menuTitle = new QLabel(menuPage);
        menuTitle->setObjectName("menuTitle");

        menuLayout->addWidget(menuTitle, 0, Qt::AlignHCenter);

        addQuestionButton = new QPushButton(menuPage);
        addQuestionButton->setObjectName("addQuestionButton");
        addQuestionButton->setMinimumHeight(60);

        menuLayout->addWidget(addQuestionButton);

        viewQuestionsButton = new QPushButton(menuPage);
        viewQuestionsButton->setObjectName("viewQuestionsButton");
        viewQuestionsButton->setMinimumHeight(60);

        menuLayout->addWidget(viewQuestionsButton);

        updateQuestionButton = new QPushButton(menuPage);
        updateQuestionButton->setObjectName("updateQuestionButton");
        updateQuestionButton->setMinimumHeight(60);

        menuLayout->addWidget(updateQuestionButton);

        deleteQuestionButton = new QPushButton(menuPage);
        deleteQuestionButton->setObjectName("deleteQuestionButton");
        deleteQuestionButton->setMinimumHeight(60);

        menuLayout->addWidget(deleteQuestionButton);

        spacer3 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        menuLayout->addItem(spacer3);

        logoutButton = new QPushButton(menuPage);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setMinimumHeight(50);

        menuLayout->addWidget(logoutButton);

        stackedWidget->addWidget(menuPage);
        addPage = new QWidget();
        addPage->setObjectName("addPage");
        addLayout = new QVBoxLayout(addPage);
        addLayout->setObjectName("addLayout");
        addTitle = new QLabel(addPage);
        addTitle->setObjectName("addTitle");

        addLayout->addWidget(addTitle);

        addForm = new QFormLayout();
        addForm->setObjectName("addForm");
        idLabel = new QLabel(addPage);
        idLabel->setObjectName("idLabel");

        addForm->setWidget(0, QFormLayout::ItemRole::LabelRole, idLabel);

        idEdit = new QLineEdit(addPage);
        idEdit->setObjectName("idEdit");

        addForm->setWidget(0, QFormLayout::ItemRole::FieldRole, idEdit);

        textLabel = new QLabel(addPage);
        textLabel->setObjectName("textLabel");

        addForm->setWidget(1, QFormLayout::ItemRole::LabelRole, textLabel);

        textEdit = new QTextEdit(addPage);
        textEdit->setObjectName("textEdit");
        textEdit->setMaximumHeight(100);

        addForm->setWidget(1, QFormLayout::ItemRole::FieldRole, textEdit);

        optALabel = new QLabel(addPage);
        optALabel->setObjectName("optALabel");

        addForm->setWidget(2, QFormLayout::ItemRole::LabelRole, optALabel);

        optAEdit = new QLineEdit(addPage);
        optAEdit->setObjectName("optAEdit");

        addForm->setWidget(2, QFormLayout::ItemRole::FieldRole, optAEdit);

        optBLabel = new QLabel(addPage);
        optBLabel->setObjectName("optBLabel");

        addForm->setWidget(3, QFormLayout::ItemRole::LabelRole, optBLabel);

        optBEdit = new QLineEdit(addPage);
        optBEdit->setObjectName("optBEdit");

        addForm->setWidget(3, QFormLayout::ItemRole::FieldRole, optBEdit);

        optCLabel = new QLabel(addPage);
        optCLabel->setObjectName("optCLabel");

        addForm->setWidget(4, QFormLayout::ItemRole::LabelRole, optCLabel);

        optCEdit = new QLineEdit(addPage);
        optCEdit->setObjectName("optCEdit");

        addForm->setWidget(4, QFormLayout::ItemRole::FieldRole, optCEdit);

        optDLabel = new QLabel(addPage);
        optDLabel->setObjectName("optDLabel");

        addForm->setWidget(5, QFormLayout::ItemRole::LabelRole, optDLabel);

        optDEdit = new QLineEdit(addPage);
        optDEdit->setObjectName("optDEdit");

        addForm->setWidget(5, QFormLayout::ItemRole::FieldRole, optDEdit);

        answerLabel = new QLabel(addPage);
        answerLabel->setObjectName("answerLabel");

        addForm->setWidget(6, QFormLayout::ItemRole::LabelRole, answerLabel);

        answerCombo = new QComboBox(addPage);
        answerCombo->setObjectName("answerCombo");

        addForm->setWidget(6, QFormLayout::ItemRole::FieldRole, answerCombo);


        addLayout->addLayout(addForm);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        saveQuestionButton = new QPushButton(addPage);
        saveQuestionButton->setObjectName("saveQuestionButton");
        saveQuestionButton->setMinimumHeight(50);

        buttonLayout->addWidget(saveQuestionButton);

        cancelButton = new QPushButton(addPage);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setMinimumHeight(50);

        buttonLayout->addWidget(cancelButton);


        addLayout->addLayout(buttonLayout);

        stackedWidget->addWidget(addPage);
        viewPage = new QWidget();
        viewPage->setObjectName("viewPage");
        viewLayout = new QVBoxLayout(viewPage);
        viewLayout->setObjectName("viewLayout");
        viewTitle = new QLabel(viewPage);
        viewTitle->setObjectName("viewTitle");

        viewLayout->addWidget(viewTitle);

        countLabel = new QLabel(viewPage);
        countLabel->setObjectName("countLabel");

        viewLayout->addWidget(countLabel);

        questionsList = new QListWidget(viewPage);
        questionsList->setObjectName("questionsList");

        viewLayout->addWidget(questionsList);

        backToMenuButton = new QPushButton(viewPage);
        backToMenuButton->setObjectName("backToMenuButton");
        backToMenuButton->setMinimumHeight(50);

        viewLayout->addWidget(backToMenuButton);

        stackedWidget->addWidget(viewPage);

        verticalLayout->addWidget(stackedWidget);

        AdminWindow->setCentralWidget(centralwidget);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        loginTitle->setText(QCoreApplication::translate("AdminWindow", "\360\237\224\220 Admin Login", nullptr));
        loginTitle->setStyleSheet(QCoreApplication::translate("AdminWindow", "font-size: 28px; font-weight: bold; color: #667eea;", nullptr));
        usernameLabel->setText(QCoreApplication::translate("AdminWindow", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("AdminWindow", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("AdminWindow", "Login", nullptr));
        menuTitle->setText(QCoreApplication::translate("AdminWindow", "Admin Menu", nullptr));
        menuTitle->setStyleSheet(QCoreApplication::translate("AdminWindow", "font-size: 24px; font-weight: bold; color: #667eea;", nullptr));
        addQuestionButton->setText(QCoreApplication::translate("AdminWindow", "\342\236\225 Add Question", nullptr));
        viewQuestionsButton->setText(QCoreApplication::translate("AdminWindow", "\360\237\223\213 View Questions", nullptr));
        updateQuestionButton->setText(QCoreApplication::translate("AdminWindow", "\342\234\217\357\270\217 Update Question", nullptr));
        deleteQuestionButton->setText(QCoreApplication::translate("AdminWindow", "\360\237\227\221\357\270\217 Delete Question", nullptr));
        logoutButton->setText(QCoreApplication::translate("AdminWindow", "\360\237\232\252 Logout", nullptr));
        addTitle->setText(QCoreApplication::translate("AdminWindow", "Add Question", nullptr));
        addTitle->setStyleSheet(QCoreApplication::translate("AdminWindow", "font-size: 24px; font-weight: bold; color: #27ae60;", nullptr));
        idLabel->setText(QCoreApplication::translate("AdminWindow", "ID:", nullptr));
        textLabel->setText(QCoreApplication::translate("AdminWindow", "Question:", nullptr));
        optALabel->setText(QCoreApplication::translate("AdminWindow", "Option A:", nullptr));
        optBLabel->setText(QCoreApplication::translate("AdminWindow", "Option B:", nullptr));
        optCLabel->setText(QCoreApplication::translate("AdminWindow", "Option C:", nullptr));
        optDLabel->setText(QCoreApplication::translate("AdminWindow", "Option D:", nullptr));
        answerLabel->setText(QCoreApplication::translate("AdminWindow", "Answer:", nullptr));
        saveQuestionButton->setText(QCoreApplication::translate("AdminWindow", "\360\237\222\276 Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("AdminWindow", "\342\235\214 Cancel", nullptr));
        viewTitle->setText(QCoreApplication::translate("AdminWindow", "View Questions", nullptr));
        viewTitle->setStyleSheet(QCoreApplication::translate("AdminWindow", "font-size: 24px; font-weight: bold; color: #3498db;", nullptr));
        countLabel->setText(QCoreApplication::translate("AdminWindow", "Total: 0 questions", nullptr));
        backToMenuButton->setText(QCoreApplication::translate("AdminWindow", "\342\206\220 Back", nullptr));
        (void)AdminWindow;
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
