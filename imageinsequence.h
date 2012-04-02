#ifndef IMAGEINSEQUENCE_H
#define IMAGEINSEQUENCE_H
#include <QString>
#include <QVariantMap>
#include <images.h>

class ImageInSequence
{
  public:
  int orderIn;
  Images img;
  QByteArray toJson();
  QVariantMap toVariantMap();
  bool fromJson(QByteArray json);
  bool fromVariant(QVariantMap variantMap);





};


#endif // IMAGEINSEQUENCE_H
