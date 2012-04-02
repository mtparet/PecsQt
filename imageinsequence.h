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

};


#endif // IMAGEINSEQUENCE_H
