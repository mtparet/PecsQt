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
    static bool saveFile(QStringList fileList);
    static bool createSequence(QMap<QString,int> mapOrder,QString name);
    static QMap<QString,int>  getListImageInSequence(Sequence* f);

};

#endif // UTIL_H
