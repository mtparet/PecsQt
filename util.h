#ifndef UTIL_H
#define UTIL_H
#include <QMap>
#include <QStringList>
#include "sequence.h"
#include "imageinsequence.h"
#include <QDir>

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
    static QList<Sequence> retrieveSeqFiles(QString pathFolder);
    static int random(int min, int max);
    static bool removeDir(const QString &dirName);
    static bool initFileSystem();
    static QPixmap getPixmapFile(QString name, QString folder);
    static bool extractRessources(const QString & filePath);
    static bool archiveRessources(const QString & filePath);
    static void recurseAddDir(QDir d, QStringList & list);
    static bool cpDir(const QString &srcPath, const QString &dstPath);
    static QList<QString> insert_at(QString id_name,int num_place, QList<QString> tab);
    static QList<int> what_free(QString side, bool only_end, int num_place,QList<QString> tab);
    static QList<QString> move_at(QString id_name,int num_place, QList<QString> tab_order);







};

#endif // UTIL_H
