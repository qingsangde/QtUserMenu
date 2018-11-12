#-------------------------------------------------
#
# Project created by QtCreator 2018-11-01T14:19:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMask
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lineform.cpp \
    animationform.cpp

HEADERS  += mainwindow.h \
    lineform.h \
    animationform.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc
