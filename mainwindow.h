#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_adminButton_clicked();
    void on_studentButton_clicked();
    void on_languageButton_clicked();

private:
    Ui::MainWindow *ui;
    int selectedLanguage = 0; // 0=not selected, 1=English, 2=German
    
    void updateUI();
    QString tr(const QString& key);
};

#endif // MAINWINDOW_H
