#include "util.h"
#include "sequence.h"
#include "imageinsequence.h"
#include <QFile>
#include <QFileInfo>

QString Util::folderImage = "images";

bool Util::saveFile(QStringList fileList){
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
    Images image;
    ImageInSequence is;
    foreach(str, listKeys){

        image.image_file = str;
        image.name =str;
        qDebug() << image.save();


        is.orderIn = mapOrder.value(str);
        is.a.clear();
        is.a = image;
        qDebug() << is.save();

        sq.addImageInSequence(is);

    }

    qDebug() << sq.save();

    return true;
}

QMap<QString,int> Util::getListImageInSequence(Sequence* f){

    QMap<QString,int> imageList;

    imageList.insert(f->is1->a->image_file,f->is1->orderIn);
    imageList.insert(f->is2->a->image_file,f->is2->orderIn);
    imageList.insert(f->is3->a->image_file,f->is3->orderIn);
    imageList.insert(f->is4->a->image_file,f->is4->orderIn);
    imageList.insert(f->is5->a->image_file,f->is5->orderIn);
    imageList.insert(f->is6->a->image_file,f->is6->orderIn);
    imageList.insert(f->is7->a->image_file,f->is7->orderIn);
    imageList.insert(f->is8->a->image_file,f->is8->orderIn);
    imageList.insert(f->is9->a->image_file,f->is9->orderIn);
    imageList.insert(f->is10->a->image_file,f->is10->orderIn);
    imageList.insert(f->is11->a->image_file,f->is11->orderIn);
    imageList.insert(f->is12->a->image_file,f->is12->orderIn);
    imageList.insert(f->is13->a->image_file,f->is13->orderIn);

    QList<QString> listKey = imageList.keys();
    QString str;
    foreach(str,listKey){
        if(str.isEmpty()){
            imageList.remove(str);
        }
    }


    return imageList;
}
