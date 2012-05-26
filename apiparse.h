#ifndef APIPARSE_H
#define APIPARSE_H

#include "sequence.h"

class ApiParse
{
public:
   static Sequence parseSeqFromROR(QVariantMap variantMap);
   static QList<Sequence> parseListFromROR(QByteArray json);
   static QList<Sequence> parseList(QByteArray json);
   static QList<Sequence> parseListFromApp(QByteArray json);
   QString folder;



};

#endif // APIPARSE_H
