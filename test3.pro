#-------------------------------------------------
#
# Project created by QtCreator 2012-03-27T17:31:56
#
#-------------------------------------------------

QT       += core gui network

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
    memory.cpp \
    editordersequence.cpp \
    mylistwidgetinternalchange.cpp \
    mybaselistwidget.cpp \
    globval.cpp \
    mylistselector.cpp \
    widgetinselector.cpp \
    organizedialog.cpp \
    onereorganizewidget.cpp \
    casewidget.cpp \
    apiparse.cpp \
    importdialog.cpp

HEADERS  += mainwindow.h \
    mylistwidget.h \
    mylistwidgetreceptor.h \
    images.h \
    imageinsequence.h \
    sequence.h \
    newsequence.h \
    util.h \
    memory.h \
    editordersequence.h \
    mylistwidgetinternalchange.h \
    mybaselistwidget.h \
    globval.h \
    mylistselector.h \
    widgetinselector.h \
    organizedialog.h \
    onereorganizewidget.h \
    casewidget.h \
    apiparse.h \
    importdialog.h

FORMS    += mainwindow.ui \
    newsequence.ui \
    editordersequence.ui \
    widgetinselector.ui \
    organizedialog.ui \
    onereorganizewidget.ui \
    casewidget.ui \
    importdialog.ui

unix|win32: LIBS += -lqjson
