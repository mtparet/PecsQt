#include "imageinsequence.h"
#include <qjson/parser.h>
#include <qjson/serializer.h>

ImageInSequence::ImageInSequence(){
}

ImageInSequence::ImageInSequence(ImageInSequence *imIn){
    this->img = new Images(imIn->img);
    this->orderIn = imIn->orderIn;
    this->folder = imIn->folder;
}

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
    imgsequence.insert("folder",folder);
    return imgsequence;
}

bool ImageInSequence::fromJson(QByteArray json){
    QJson::Parser parser;
    bool ok;

    QVariantMap result = parser.parse (json, &ok).toMap();
    if (!ok) {
        qFatal("An error occurred during parsing");
        return ok;
    }

    return this->fromVariant(result);
}

bool ImageInSequence::fromVariant(QVariantMap variantMap){
    ImageInSequence();
    orderIn = variantMap["orderIn"].toInt();
    img.fromVariant(variantMap["img"].toMap());
    folder = variantMap["folder"].toString();
    return true;
}

bool ImageInSequence::lessThan(ImageInSequence &a, ImageInSequence &b)
{
   return a.orderIn < b.orderIn;
}



