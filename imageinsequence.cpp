#include "imageinsequence.h"
#include "serializer.h"

QByteArray ImageInSequence::toJson(){
    QVariantMap imgsequence = this->toVariantMap();
    QJson::Serializer serializer;
    QByteArray json = serializer.serialize(imgsequence);
    return json;
}

QVariantMap ImageInSequence::toVariantMap(){
    QVariantMap imgsequence;
    imgsequence.insert("orderIn",orderIn);
    imgsequence.insert("img",img.toVariantMap());
    return imgsequence;
}


