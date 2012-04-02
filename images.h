#ifndef IMAGES_H
#define IMAGES_H
#include <QString>
#include <QVariantMap>


class Images
{

  public:
    QString name;
    QString image_file;
    QByteArray toJson();
    QVariantMap toVariantMap();


};

#endif // IMAGES_H
