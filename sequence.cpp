#include <sequence.h>
#include <QStringList>
#include "serializer.h"
#include "parser.h"

Sequence::Sequence(){

}

Sequence::Sequence(Sequence *sq){
    this->name = sq->name;
    ImageInSequence is;
    foreach(is,sq->listImageInSequence){
        ImageInSequence is2 = new ImageInSequence(is);
        this->listImageInSequence << is2;
    }

}

QByteArray Sequence::toJson(){
    QVariantMap sequence = this->toVariantMap();
    QJson::Serializer serializer;
    QByteArray json = serializer.serialize(sequence);
    return json;
}

QVariantMap Sequence::toVariantMap(){
    QVariantMap imgsequence;
    imgsequence.insert("name",name);

    QVariantList variantListImg;
    ImageInSequence imgSeq;
    foreach(imgSeq,listImageInSequence){
        variantListImg << imgSeq.toVariantMap();
    }
    imgsequence.insert("listImageInSequence",variantListImg);
    return imgsequence;

}

bool Sequence::fromJson(QByteArray json){
    QJson::Parser parser;
    bool ok;

    QVariantMap result = parser.parse (json, &ok).toMap();
    if (!ok) {
        qFatal("An error occurred during parsing");
        return ok;
    }

    return this->fromVariant(result);
}

bool Sequence::fromVariant(QVariantMap variantMap){
    name = variantMap["name"].toString();
    foreach (QVariant imgSeqVariant, variantMap["listImageInSequence"].toList()) {
       ImageInSequence imgSeq;
       imgSeq.fromVariant(imgSeqVariant.toMap());
       listImageInSequence << imgSeq;
    }
    return true;
}

bool Sequence::changeOrderOf(QString name, int orderIn){
    ImageInSequence imgSeq;
    int i = 0;
    for(i = 0; i < listImageInSequence.count(); i++){
        imgSeq = listImageInSequence.value(i);
        if(imgSeq.img.name == name){
            imgSeq.orderIn = orderIn;
            listImageInSequence.replace(i,imgSeq);
        }
    }

    return true;
}

bool Sequence::setOrder(QMap<QString,int> orderMap){

    QList<QString> keysList = orderMap.keys();
    QString str;
    foreach(str,keysList){
        this->changeOrderOf(str,orderMap.value(str));
    }

    return true;
}

bool  Sequence::fromQMap(QStringList listName,QString name){

    this->name = name;

    QString str;
    int order = 1;
    foreach(str, listName){
        Images image;
        image.image_file = str;
        image.name = str;

        ImageInSequence is;
        is.orderIn = order;
        is.img = image;

        listImageInSequence << is;
        order++;
    }

    return true;
}





