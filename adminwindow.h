#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "Question.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(int language, QWidget *parent = nullptr);
    ~AdminWindow();

signals:
    void windowClosed();

private slots:
    void on_loginButton_clicked();
    void on_addQuestionButton_clicked();
    void on_viewQuestionsButton_clicked();
    void on_updateQuestionButton_clicked();
    void on_deleteQuestionButton_clicked();
    void on_logoutButton_clicked();
    void on_saveQuestionButton_clicked();
    void on_cancelButton_clicked();
    void on_backToMenuButton_clicked();

private:
    Ui::AdminWindow *ui;
    int language;
    bool isLoggedIn = false;
    QVector<Question> questions;
    
    void setupPages();
    void showLoginPage();
    void showMenuPage();
    void showAddQuestionPage();
    void showViewQuestionsPage();
    void loadQuestionsList();
    QString tr(const QString& key);
    void showMessage(const QString& msg, bool isError);
};

#endif // ADMINWINDOW_H
