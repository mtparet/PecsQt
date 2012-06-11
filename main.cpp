#include <QtGui/QApplication>
#include "mainwindow.h"
#include "images.h"
#include "sequence.h"
#include "util.h"
#include "imageinsequence.h"
#include "memory.h"
#include "globval.h"
#include <QMetaObject>
#include <QTextCodec>
#include <QSize>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    Util::initFileSystem();
    QList<Sequence> listSq;
    listSq = Util::retrieveSeqFiles(Util::folderRacine + "/" + Util::folderSequence);

    Sequence sq;
    foreach(sq,listSq){
        myMem.add(sq);
    }

    myMem.size_in_view =  new QSize(100,100);
    myMem.size_in_widget = new QSize(100,100);

    MainWindow w;
    w.show();

    
    return a.exec();
}
