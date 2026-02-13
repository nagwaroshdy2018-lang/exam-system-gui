#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Set application-wide font
    QFont font("Segoe UI", 10);
    font.setStyleHint(QFont::SansSerif);
    a.setFont(font);
    
    // Set modern fusion style
    a.setStyle(QStyleFactory::create("Fusion"));
    
    MainWindow w;
    w.show();
    
    return a.exec();
}
