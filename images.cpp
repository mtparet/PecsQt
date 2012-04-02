#include "images.h"
#include <QVariantMap>
#include "serializer.h"

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
