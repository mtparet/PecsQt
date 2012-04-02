#include "util.h"
#include "sequence.h"
#include "imageinsequence.h"
#include <QFile>
#include <QFileInfo>

QString Util::folderImage = "images";

bool Util::saveFiles(QStringList fileList){
    bool check;
    QFile file;
    QString str;
    foreach(str,fileList){
        file.setFileName(str);
        QFileInfo fileInfo(file);
        check = file.copy(Util::folderImage + "/" + fileInfo.fileName());
    }


    return check;
}

bool Util::createSequence(QMap<QString,int> mapOrder,QString name){
    Sequence sq;
    sq.name = name;

    QList<QString> listKeys = mapOrder.keys();
    QString str;



    foreach(str, listKeys){
        Images image;
        image.image_file = str;
        image.name = str;

        ImageInSequence is;
        is.orderIn = mapOrder.value(str);
        is.a = image;

    }

    return true;
}
