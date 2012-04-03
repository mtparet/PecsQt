#include "util.h"
#include "sequence.h"
#include "imageinsequence.h"
 #include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QImage>
#include <QIcon>
#include <QDebug>

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

bool Util::saveOneSeq(Sequence f){
    QByteArray json = f.toJson();
     QFile file;
     QString location = f.name + ".json";
     file.setFileName(location);
     bool test = file.open(QIODevice::WriteOnly);
     QDataStream out(&file);
     out << json;
}

bool Util::saveAllSeq(QList<Sequence> listQ){
    Sequence sq;
    foreach(sq,listQ){
        Util::saveOneSeq(sq);
    }
    return true;
}

QList<Sequence> Util::retrieveAllSeq(){
    QList<Sequence> listSq;
    QStringList fileJson;
    QDir qDir;
    qDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList listFile = qDir.entryInfoList();


    QFileInfo file1;
    foreach(file1,listFile){
        qDebug() << file1.fileName();
        if (file1.suffix() == "json"){
            fileJson << file1.fileName();
        }
    }


    QString str;
    foreach(str,fileJson){
        QFile file;
        file.setFileName(str);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        QByteArray json;
        in >> json;

        Sequence sq;
        sq.fromJson(json);
        listSq << sq;
    }

    return listSq;
}

bool Util::removeOneSeq(Sequence sq){
    QFile file;
    QString location = sq.name + ".json";
    file.setFileName(location);
    file.remove();
}

bool Util::removeAllSeq(QList<Sequence> listQ){
    Sequence sq;
    foreach(sq,listQ){
        Util::removeOneSeq(sq);
    }
    return true;
}


