#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QButtonGroup>
#include "Question.h"

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentWindow(int language, QWidget *parent = nullptr);
    ~StudentWindow();

signals:
    void finished();

private slots:
    void on_loginButton_clicked();
    void on_startExamButton_clicked();
    void on_submitButton_clicked();
    void on_nextButton_clicked();
    void updateTimer();

private:
    Ui::StudentWindow *ui;
    int language;
    QString studentId;
    QVector<Question> questions;
    int currentQuestionIndex;
    int correctCount;
    int timeRemaining;
    QTimer* examTimer;
    QTimer* countdownTimer;
    QButtonGroup* answerGroup;
    
    void setupPages();
    void showLoginPage();
    void showInstructionsPage();
    void showExamPage();
    void showResultsPage();
    void loadCurrentQuestion();
    void finishExam(bool timeUp);
    QString tr(const QString& key);
    void showMessage(const QString& msg, bool isError);
};

#endif // STUDENTWINDOW_H
