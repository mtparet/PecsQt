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
    static QImage getImage(QString name);
    static QStringList getFileName(QStringList fileList);
    static QIcon getIcon(QString name);


};

#endif // UTIL_H
