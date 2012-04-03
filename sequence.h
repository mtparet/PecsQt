#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <imageinsequence.h>
#include <QString>
#include <QVariantMap>
#include <QMap>

class Sequence
{

public:
      QString name;
      QList<ImageInSequence> listImageInSequence;
      QByteArray toJson();
      QVariantMap toVariantMap();
      bool fromQMap(QStringList listName,QString name);
      bool setOrder(QMap<QString,int> orderMap);
      bool changeOrderOf(QString name, int orderIn);
      bool fromVariant(QVariantMap variantMap);
      bool fromJson(QByteArray json);




private:

};

#endif // SEQUENCE_H
