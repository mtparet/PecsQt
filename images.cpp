#include "images.h"
#include <QVariantMap>
#include "parser.h"
#include "serializer.h"

Images::Images(){

}

Images::Images(Images *img){
    this->image_file = img->image_file;
    this->name = img->image_file;
}

QByteArray Images::toJson(){
    QVariantMap image = this->toVariantMap();
    QJson::Serializer serializer;
    QByteArray json = serializer.serialize(image);
    return json;
}

QVariantMap Images::toVariantMap(){
    QVariantMap image;
    image.insert("name",name);
    image.insert("image_file",image_file);
    return image;
}

bool Images::fromJson(QByteArray json){
    QJson::Parser parser;
    bool ok;

    QVariantMap result = parser.parse (json, &ok).toMap();
    if (!ok) {
        qFatal("An error occurred during parsing");
        return ok;
    }

    return this->fromVariant(result);
}

bool Images::fromVariant(QVariantMap variantMap){
    name = variantMap["name"].toString();
    image_file = variantMap["image_file"].toString();
    return true;
}

