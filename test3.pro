#-------------------------------------------------
#
# Project created by QtCreator 2012-03-27T17:31:56
#
#-------------------------------------------------

QT       += core gui

TARGET = test3
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    mylistwidget.cpp \
    mylistwidgetreceptor.cpp \
    images.cpp \
    imageinsequence.cpp \
    sequence.cpp \
    newsequence.cpp \
    util.cpp \
    memory.cpp

HEADERS  += mainwindow.h \
    mylistwidget.h \
    mylistwidgetreceptor.h \
    images.h \
    imageinsequence.h \
    sequence.h \
    newsequence.h \
    util.h \
    memory.h \
    global.h

FORMS    += mainwindow.ui \
    newsequence.ui

LIBS += -L/home/mtparet3/qjson/build/lib -lqjson
INCLUDEPATH = /home/mtparet3/qjson/src/

