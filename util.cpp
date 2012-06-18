#include "util.h"
#include "sequence.h"
#include "imageinsequence.h"
#include <QDirIterator>
#include <QFile>
#include <QFileInfo>
#include <QImage>
#include <QIcon>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QEventLoop>
#include <QNetworkRequest>

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

void Util::saveImageFilesFromNetwork(QStringList urlString,QString folder){
   /*
    QNetworkAccessManager* mNetworkManager = new QNetworkAccessManager(this);
    QObject::connect(mNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onNetworkReply(QNetworkReply*)));

    QUrl url = "http://someurl.com";
    QNetworkReply* reply = mNetworkManager->get(QNetworkRequest(url));

    void onNetworkReply(QNetworkReply* reply)
    {
        QString replyString;
        if(reply->error() == QNetworkReply::NoError)
        {
            int httpstatuscode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toUInt();
            switch(httpstatuscode)
            {
            case RESPONSE_OK:
            if (reply->isReadable())
            {
                QFileInfo fileInfo(fileurl.path());

                QFile file(Util::folderRacine + "/" + Util::folderImage  + "/" + folder + "/" + fileInfo.fileName());
                file.open(QIODevice::WriteOnly);
                file.write(reply->readAll());
                //Assuming this is a human readable file replyString now contains the file
                replyString = QString::fromUtf8(reply->readAll().data());
            }
            break;
            case RESPONSE_ERROR:
            case RESPONSE_BAD_REQUEST:
            default:
                break;
            }
        }

        reply->deleteLater();
    }
    */
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
    QString image_location;
    if(folder == "null"){
        image_location = Util::folderRacine +"/"+ Util::folderImage + "/" + name;
    }else{
        image_location = Util::folderRacine +"/"+ Util::folderImage + "/" + folder + "/" + name;

    }
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


/* Ins√©rer dans tableau de taille fixe de l'√©l√©ment id_name √  la place num_place
    Si la place en dehors du tableau on ne fait rien
    Si la place √©tait avant vide on a simplement une insertion √  cette place
    Si la place √©tait occup√©e, le reste du tableau est d√©plac√©:
        soit sur la droite ou la gauche en fonction du plus grand nombre de place vide restant √  la fin du tableau
        Si il ne reste plus de place √  la toute fin du tableau de chaque c√¥t√©, il est d√©plac√© :
          soit √  droite ou gauche en fonction des places vides non finales */
QList<QString> Util::insert_at(QString id_name,int num_place, QList<QString> tab){

    if(num_place < tab.length()){
        if(tab[num_place] == "null"){
            tab[num_place] = id_name;
        }else{
            QList<int> free_right = what_free("right", true, num_place, tab);
            QList<int> free_left = what_free("left", true, num_place, tab);

            // on test si le nombre d'√©l√©ment dans free_left est > √  celui dans free_right et qu'il n'est donc pas √©gal √  0
            if(free_left.length() > free_right.length()){
                tab.removeAt(free_left[0]);
                tab.insert(num_place,id_name);
            }else{
                // si on v√©rifie que l'un des deux ne sont pas √©gal √  0 (et donc que free_right n'est pas √©gal √  0)
                if(free_right.length() != 0 || free_left.length() != 0){
                    tab.removeAt(free_right[0]);
                    tab.insert(num_place,id_name);
                }else
                    // sinon on recommence en prenant en compte toutes les cases
                {
                    QList<int> free_right_all = what_free("right", false, num_place, tab);
                    QList<int> free_left_all = what_free("left", false, num_place, tab);
                    // on test si le nombre d'√©l√©ment dans free_left est > √  celui dans free_right et qu'il n'est donc pas √©gal √  0
                    if(free_left_all.length() > free_right_all.length()){
                        tab.removeAt(free_left_all[0]);
                        tab.insert(num_place,id_name);
                    }else{
                        // si on v√©rifie que l'un des deux ne sont pas √©gal √  0 (et donc que free_right n'est pas √©gal √  0)
                        if(free_right_all.length() != 0 || free_left_all.length() != 0){
                            tab.removeAt(free_right_all[0]);
                            tab.insert(num_place,id_name);
                        }
                    }
                }
            }

        }
    }
    return tab;
}


/* calcul le nombre de place vide √  partir d'une certaine place dans un tableau :
    √  gauche, droite, qu'√  la fin, de partout
  side : left ou right
  only_end : true or false
  num_place : le num√©ro de la place
  tab : le tableau
  renvoit un tableau avec les num√©ros des places libres suivant les conditions
  l'odre des places dans le tableau est indicatif pour le premier √©l√©ment √  supprimer si r√©organisation du tableau
  */
QList<int> Util::what_free(QString side, bool only_end, int num_place,QList<QString> tab){
    QList<int> tab_free;
    if(num_place < tab.length()){
        if(side == "left"){
            if(only_end){
                int i = 0;
                QString case_prev;
                do{
                    case_prev = tab[i];
                    if(case_prev == "null"){
                        tab_free.append(i);
                    }
                    i++;
                }
                while( case_prev == "null" && i <= num_place);
            }else{
                for(int i = num_place; i >= 0; i--){
                    if(tab[i] == "null"){
                        tab_free.append(i);
                    }
                }
            }
        }else{
            if (side == "right"){
                if(only_end){
                    int i = tab.length() - 1;
                    QString case_prev;
                    do{
                        case_prev = tab[i];
                        if(case_prev == "null"){
                            tab_free.append(i);
                        }
                        i--;
                    }
                    while( case_prev == "null" && i >= num_place);
                }else{
                    for(int i = num_place; i < tab.length(); i++){
                        if(tab[i] == "null"){
                            tab_free.append(i);
                        }
                    }
                }
            }
        }
        return tab_free;
    }
}

/* on d√©place id_name √  la place num_place
        pour se faire on stocke l'√©l√©ment √  d√©placer, on lib√®re la place o√π il √©tait
        et on appelle la fonction d'insertion */
QList<QString> Util::move_at(QString id_name,int num_place, QList<QString> tab_order){
    int index_id = tab_order.indexOf(id_name);
    tab_order[index_id] = "null";
    return insert_at(id_name,num_place,tab_order);
}


