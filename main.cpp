#include <QtGui/QApplication>
#include "mainwindow.h"
#include "images.h"
#include "sequence.h"
#include "util.h"
#include "imageinsequence.h"
#include "memory.h"
#include "globval.h"
#include <QMetaObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Util::initFileSystem();
    QList<Sequence> listSq;
    listSq = Util::retrieveSeqFiles(Util::folderRacine + "/" + Util::folderSequence);
    myMem.listSequence = listSq;
    MainWindow w;
    w.show();

    
    return a.exec();
}
