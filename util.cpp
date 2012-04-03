#include "util.h"
#include "sequence.h"
#include "imageinsequence.h"
#include <QFile>
#include <QFileInfo>
#include <QImage>
#include <QIcon>

QString Util::folderImage = "images";

QStringList Util::getFileName(QStringList fileList){
    QStringList nameList;
    QFile file;
    QString str;
    foreach(str,fileList){
        file.setFileName(str);
        QFileInfo fileInfo(file);
        nameList << fileInfo.fileName();
    }
    return nameList;
}

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

QImage Util::getImage(QString name){
    QString image_location = Util::folderImage + "/" + name;
    QImage img;
    img.load(image_location);
    return img;
}

QIcon Util::getIcon(QString name){
    QString image_location = Util::folderImage + "/" + name;
    QIcon img = QIcon(image_location);
    return img;
}


