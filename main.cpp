#include <QtGui/QApplication>
#include "mainwindow.h"
#include "images.h"
#include "sequence.h"
#include "util.h"
#include "imageinsequence.h"
#include "memory.h"
#include <QDebug>
#include <QMetaObject>

static Memory myMem;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMap<QString,int> mapOrder;
    mapOrder.insert("test",5);
    mapOrder.insert("test2",7);
    mapOrder.insert("test3",8);


    Sequence s = Util::createSequence(mapOrder,"bonjour");

    MainWindow w;
    w.show();

    
    return a.exec();
}
