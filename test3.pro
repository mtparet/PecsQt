#-------------------------------------------------
#
# Project created by QtCreator 2012-03-27T17:31:56
#
#-------------------------------------------------

include (/home/mtparet3/dquest/src/dquest.pri)

QT       += core gui sql

TARGET = test3
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    mylistwidget.cpp \
    mylistwidgetreceptor.cpp \
    images.cpp \
    database.cpp \
    model.cpp

HEADERS  += mainwindow.h \
    mylistwidget.h \
    mylistwidgetreceptor.h \
    images.h \
    database.h \
    model.h

FORMS    += mainwindow.ui
