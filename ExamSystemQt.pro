QT       += core gui widgets

CONFIG += c++11

TARGET = ExamSystemQt
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    adminwindow.cpp \
    studentwindow.cpp \
    question.cpp \
    examdata.cpp

HEADERS += \
    mainwindow.h \
    adminwindow.h \
    studentwindow.h \
    Question.h \
    examdata.h

FORMS += \
    mainwindow.ui \
    adminwindow.ui \
    studentwindow.ui

RESOURCES += \
    resources.qrc

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
