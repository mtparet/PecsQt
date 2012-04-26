#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <imageinsequence.h>
#include <QString>
#include <QVariantMap>
#include <QMap>

class Sequence
{

public:
    Sequence();
    Sequence(Sequence *sq);
      QString name;
      QList<ImageInSequence> listImageInSequence;
      ImageInSequence getImageInsequence(QString name);
      QByteArray toJson();
      QVariantMap toVariantMap();
      bool fromQMap(QStringList listName,QString name);
      bool setOrder(QMap<QString,int> orderMap);
      bool changeOrderOf(QString name, int orderIn);
      bool fromVariant(QVariantMap variantMap);
      bool fromJson(QByteArray json);
      bool changeAndSaveImageFile();




private:

};

#endif // SEQUENCE_H
