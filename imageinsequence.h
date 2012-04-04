#ifndef IMAGEINSEQUENCE_H
#define IMAGEINSEQUENCE_H
#include <QString>
#include <QVariantMap>
#include <images.h>

class ImageInSequence
{
  public:
    ImageInSequence();
    ImageInSequence(ImageInSequence *imIn);
  int orderIn;
  Images img;
  QByteArray toJson();
  QVariantMap toVariantMap();
  bool fromJson(QByteArray json);
  bool fromVariant(QVariantMap variantMap);
  static bool lessThan(ImageInSequence &a, ImageInSequence &b);





};


#endif // IMAGEINSEQUENCE_H
