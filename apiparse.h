#ifndef APIPARSE_H
#define APIPARSE_H

#include "sequence.h"

class ApiParse
{
public:
    static Sequence parseSeqFromROR(QVariantMap variantMap);
    static QList<Sequence> parseListFromROR(QByteArray json);

};

#endif // APIPARSE_H
