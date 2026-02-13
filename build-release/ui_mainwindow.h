/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *adminButton;
    QPushButton *studentButton;
    QSpacerItem *verticalSpacer2;
    QPushButton *languageButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel, 0, Qt::AlignHCenter);

        subtitleLabel = new QLabel(centralwidget);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(subtitleLabel, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        adminButton = new QPushButton(centralwidget);
        adminButton->setObjectName("adminButton");

        verticalLayout->addWidget(adminButton, 0, Qt::AlignHCenter);

        studentButton = new QPushButton(centralwidget);
        studentButton->setObjectName("studentButton");

        verticalLayout->addWidget(studentButton, 0, Qt::AlignHCenter);

        verticalSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer2);

        languageButton = new QPushButton(centralwidget);
        languageButton->setObjectName("languageButton");

        verticalLayout->addWidget(languageButton, 0, Qt::AlignHCenter);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Welcome!", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("MainWindow", "Select Your Role", nullptr));
        adminButton->setText(QCoreApplication::translate("MainWindow", "\360\237\221\250\342\200\215\360\237\222\274 Admin", nullptr));
        studentButton->setText(QCoreApplication::translate("MainWindow", "\360\237\221\250\342\200\215\360\237\216\223 Student", nullptr));
        languageButton->setText(QCoreApplication::translate("MainWindow", "\360\237\214\220 Language (EN)", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
