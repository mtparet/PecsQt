#include <QtGui/QApplication>
#include "mainwindow.h"
#include "images.h"
#include "sequence.h"
#include "util.h"
#include "imageinsequence.h"
#include <QDebug>
#include <QMetaObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Images im;
    im.name = "nom_image";
    im.image_file = "path_to_file";
    im.toJson();

    QByteArray json = "{ \"image_file\" : \"path_to_file\", \"name\" : \"nom_image\" }";

    QByteArray json2 =  "{ \"listImageInSequence\" : [ { \"img\" : { \"image_file\" : \"path_to_file\", \"name\" : \"nom_image\" }, \"orderIn\" : 5 }, { \"img\" : { \"image_file\" : \"path_to_file\", \"name\" : \"nom_image\" }, \"orderIn\" : 7 } ], \"name\" : \"sequence\" }";

    ImageInSequence imgSeq;
    imgSeq.orderIn = 5;
    imgSeq.img = im;
    imgSeq.toJson();

    ImageInSequence imgSeq2;
    imgSeq2.orderIn = 7;
    imgSeq2.img = im;
    imgSeq2.toJson();

    Sequence sq;
    sq.name = "sequence";
    sq.listImageInSequence.insert(sq.listImageInSequence.count(),imgSeq);
    sq.listImageInSequence.insert(sq.listImageInSequence.count(),imgSeq2);

    sq.toJson();

    //Images testJson;
    //testJson.fromJson(json);

    Sequence sq2;
    sq2.fromJson(json2);

    qDebug() << sq2.toJson();

    MainWindow w;
    w.show();

    
    return a.exec();
}
