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
    static bool saveOneSeq(Sequence f);
    static bool saveAllSeq(QList<Sequence> listQ);
    static bool removeOneSeq(Sequence sq);
    static bool removeAllSeq(QList<Sequence> listQ);
    static QList<Sequence> retrieveAllSeq();





};

#endif // UTIL_H
