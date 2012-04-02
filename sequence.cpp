#include <sequence.h>
#include "serializer.h"
#include "parser.h"

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





