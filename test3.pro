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
    images.cpp \
    imageinsequence.cpp \
    sequence.cpp \
    newsequence.cpp \
    util.cpp \
    memory.cpp \
    editordersequence.cpp \
    globval.cpp \
    mylistselector.cpp \
    widgetinselector.cpp \
    organizedialog.cpp \
    onereorganizewidget.cpp \
    apiparse.cpp \
    importdialog.cpp \
    imagewidget.cpp \
    imagereceptordelegate.cpp \
    imageseqmodel.cpp \
    mybaselistview.cpp \
    mylistwidgetinternalchange.cpp \
    mybaselistwidget.cpp

HEADERS  += mainwindow.h \
    images.h \
    imageinsequence.h \
    sequence.h \
    newsequence.h \
    util.h \
    memory.h \
    editordersequence.h \
    mybaselistwidget.h \
    globval.h \
    mylistselector.h \
    widgetinselector.h \
    organizedialog.h \
    onereorganizewidget.h \
    apiparse.h \
    importdialog.h \
    imagewidget.h \
    imagereceptordelegate.h \
    imageseqmodel.h \
    mybaselistview.h \
    mylistwidgetinternalchange.h

FORMS    += mainwindow.ui \
    newsequence.ui \
    editordersequence.ui \
    widgetinselector.ui \
    organizedialog.ui \
    onereorganizewidget.ui \
    importdialog.ui \
    imagewidget.ui

#unix|win32: LIBS += -lqjson

INCLUDEPATH += $$PWD/../qjson
DEPENDPATH += $$PWD/../qjson
LIBS += $$PWD/../qjson/build/lib/libqjson.dll
INCLUDEPATH += $$PWD/../qjson/src/









