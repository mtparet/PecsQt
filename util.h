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
    static QString folderRacine;
    static QString folderSequence;
    static bool saveImageFiles(QStringList fileList,QString folder);
    static QImage getImageFile(QString name,QString folder);
    static QStringList getFileName(QStringList fileList);
    static QIcon getIcon(QString name, QString folder);
    static bool saveOneSeq(Sequence f);
    static bool saveAllSeq(QList<Sequence> listQ);
    static bool removeSeqFile(Sequence sq);
    static bool removeAllSeqFiles(QList<Sequence> listQ);
    static QList<Sequence> retrieveSeqFiles();
    static int random(int min, int max);
    static bool removeDir(const QString &dirName);
    static bool initFileSystem();





};

#endif // UTIL_H
