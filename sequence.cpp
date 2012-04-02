#include <sequence.h>
#include "serializer.h"
#include <QDebug>

QByteArray Sequence::toJson(){
    QVariantMap sequence = this->toVariantMap();
    QJson::Serializer serializer;
    QByteArray json = serializer.serialize(sequence);
    qDebug() << json;
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

    qDebug() << imgsequence;
    return imgsequence;

}


