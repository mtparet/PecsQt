#ifndef UTIL_H
#define UTIL_H
#include <QMap>
#include <QStringList>
#include "sequence.h"
#include "imageinsequence.h"

class Util
{
public:
    static QString folderImage;
    static bool saveFiles(QStringList fileList);
    static bool createSequence(QMap<QString,int> mapOrder,QString name);

};

#endif // UTIL_H
