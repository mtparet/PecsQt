#include "imageinsequence.h"
#include "serializer.h"
#include "parser.h"

ImageInSequence::ImageInSequence(){

}

ImageInSequence::ImageInSequence(ImageInSequence *imIn){
    this->img = new Images(imIn->img);
    this->orderIn = imIn->orderIn;
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
    orderIn = variantMap["orderIn"].toInt();
    img.fromVariant(variantMap["img"].toMap());
    return true;
}

bool ImageInSequence::lessThan(ImageInSequence &a, ImageInSequence &b)
{
   return a.orderIn < b.orderIn;
}



