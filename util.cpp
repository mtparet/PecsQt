#include "util.h"
#include "sequence.h"
#include "imageinsequence.h"
 #include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QImage>
#include <QIcon>
#include <QDebug>


QString Util::folderRacine = "ressources";
QString Util::folderImage = "images";
QString Util::folderSequence = "sequences";

bool Util::initFileSystem(){
    bool result = true;

    if(!QDir(Util::folderRacine).exists()){
        if(!QDir().mkdir(Util::folderRacine)){
            result = false;
        }
    }
    if(!QDir(Util::folderRacine + "/" + Util::folderImage).exists()){
        if(!QDir().mkdir(Util::folderRacine + "/"+ Util::folderImage)){
             result = false;
        }
    }
    if(!QDir(Util::folderRacine + "/" + Util::folderSequence).exists()){
        if(!QDir().mkdir(Util::folderRacine + "/" + Util::folderSequence)){
             result = false;
        }
    }

    return result;

}

QStringList Util::getFileName(QStringList fileList){
    QStringList nameList;
    QFile file;
    QString str;
    foreach(str,fileList){
        file.setFileName(str);
        QFileInfo fileInfo(file);
        nameList << fileInfo.fileName();
    }
    return nameList;
}

bool Util::saveImageFiles(QStringList fileList,QString folder ){
    bool check;

    if(!QDir(Util::folderRacine + "/" + Util::folderImage + "/" + folder ).exists()){
        if(!QDir().mkdir(Util::folderRacine + "/" + Util::folderImage + "/" + folder)){
            check = false;
        }
    }

    QFile file;
    QString str;
    foreach(str,fileList){
        file.setFileName(str);
        QFileInfo fileInfo(file);
        check = file.copy( Util::folderRacine + "/" + Util::folderImage  + "/" + folder + "/" + fileInfo.fileName());
    }


    return check;
}

QImage Util::getImageFile(QString name,QString folder){
    QString image_location = Util::folderRacine + "/" + Util::folderImage + "/" + folder + "/" + name;
    QImage img;
    img.load(image_location);
    return img;
}

QIcon Util::getIcon(QString name, QString folder){
    QString image_location = Util::folderRacine +"/"+ Util::folderImage + "/" + folder + "/" + name;
    QIcon img = QIcon(image_location);
    return img;
}

QPixmap Util::getPixmapFile(QString name, QString folder){
    QString image_location = Util::folderRacine +"/"+ Util::folderImage + "/" + folder + "/" + name;
    QPixmap img = QPixmap(image_location);
    return img;
}

bool Util::saveOneSeq(Sequence f){
     QByteArray json = f.toJson();
     QFile file;
     QString location = Util::folderRacine + "/" + Util::folderSequence + "/" + f.name + ".json";
     file.setFileName(location);
     bool test = file.open(QIODevice::WriteOnly);
     QDataStream out(&file);
     out << json;
}

bool Util::saveAllSeq(QList<Sequence> listQ){
    Sequence sq;
    foreach(sq,listQ){
        Util::saveOneSeq(sq);
    }
    return true;
}

QList<Sequence> Util::retrieveSeqFiles(QString pathFolder){
    QList<Sequence> listSq;
    QStringList fileJson;
    QDir qDir(pathFolder);
    qDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList listFile = qDir.entryInfoList();

    QFileInfo file1;
    foreach(file1,listFile){
        qDebug() << file1.fileName();
        if (file1.suffix() == "json"){
            fileJson << file1.fileName();
        }
    }


    QString str;
    foreach(str,fileJson){
        QFile file;
        file.setFileName(Util::folderRacine + "/" + Util::folderSequence + "/" + str);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        QByteArray json;
        in >> json;

        Sequence sq;
        sq.fromJson(json);
        listSq << sq;
    }

    return listSq;
}

bool Util::removeSeqFile(Sequence sq){
    QFile file;
    QString location = Util::folderRacine + "/" + Util::folderSequence + "/" + sq.name + ".json";
    file.setFileName(location);
    file.remove();
    removeDir(Util::folderRacine + "/" + Util::folderImage + sq.name);
}

bool Util::removeAllSeqFiles(QList<Sequence> listQ){
    Sequence sq;
    foreach(sq,listQ){
        Util::removeSeqFile(sq);
    }
    return true;
}

int Util::random(int min, int max){
    return static_cast<int>(min + (static_cast<float>(qrand()) / RAND_MAX * (max - min + 1)));
}

/*!
   Delete a directory along with all of its contents.

   \param dirName Path of directory to remove.
   \return true on success; false on error.
*/
bool Util::removeDir(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeDir(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }

    return result;
}

bool Util::extractRessources(const QString & filePath){
    QDir dir(Util::folderRacine);

        Util::cpDir(dir.absolutePath(),filePath + "/" + Util::folderRacine);

        return true;
}


bool Util::archiveRessources(const QString & filePath){
    QDir qdirJ(Util::folderRacine + "/" + Util::folderSequence);
        QDir qdirI(Util::folderRacine + "/" + Util::folderImage);
        QString where = "sequences.zip";
        QString where2 = "images.zip";

        return true;
}

bool Util::cpDir(const QString &srcPath, const QString &dstPath)
{
    //rmDir(dstPath);
    QDir parentDstDir(QFileInfo(dstPath).path());
    QString path = parentDstDir.path();
    QString path2 = path;
    if (!parentDstDir.mkdir(QFileInfo(dstPath).fileName()))
        return false;

    QDir srcDir(srcPath);
    foreach(const QFileInfo &info, srcDir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
        QString srcItemPath = srcPath + "/" + info.fileName();
        QString dstItemPath = dstPath + "/" + info.fileName();
        if (info.isDir()) {
            if (!cpDir(srcItemPath, dstItemPath)) {
                return false;
            }
        } else if (info.isFile()) {
            if (!QFile::copy(srcItemPath, dstItemPath)) {
                return false;
            }
        } else {
            qDebug() << "Unhandled item" << info.filePath() << "in cpDir";
        }
    }
    return true;
}

void Util::download(String url,QString where){

}


