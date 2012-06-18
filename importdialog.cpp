#include "importdialog.h"
#include "ui_importdialog.h"
#include <QMessageBox>
#include "apiparse.h"
#include "globval.h"
#include "memory.h"
#include "util.h"
#include <QFileDialog>

ImportDialog::ImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportDialog)
{
    ui->setupUi(this);

}

ImportDialog::~ImportDialog()
{
    delete ui;
}

void ImportDialog::telechargement()
{
    const QUrl url = QUrl(ui->lineEdit->text()); //On rcupre l'URL entre par l'utilisateur.
    const QNetworkRequest requete(url); //On cre notre requte
    QNetworkAccessManager *m = new QNetworkAccessManager;
    QNetworkReply *r = m->get(requete);
    connect(r, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(messageErreur(QNetworkReply::NetworkError)));
    connect(r, SIGNAL(finished()), this, SLOT(afficher()));
    connect(r, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(progressionDownload(qint64, qint64) ));
}

void ImportDialog::afficher()
{
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender()); //On rcupre la rponse du serveur
    QString url_base = r->url().path();

    QByteArray json = r->readAll();
    QList<Sequence> listSq = ApiParse::parseList(json);



    Sequence sq;
    foreach(sq,listSq){
        listSeq.append(&sq);

        QStringList fileList;

        ImageInSequence is;
        foreach(is,sq.listImageInSequence){
            fileList.append(url_base + is.img.image_file);
        }

        Util::saveImageFiles(fileList, sq.name);

        QStringList listeName = Util::getFileName(fileList);

        sq.fromQMap(listeName,sq.name);

        //add folder name to image_file
        for(int i = 0; i < sq.listImageInSequence.count(); i++){
            sq.listImageInSequence[i].folder = sq.name;
        }
    }

    myMem.add(sq);

    ui->label_3->setText(listSeq.count() + " sÈquences ‡ importer");

    r->deleteLater();
}

void ImportDialog::messageErreur(QNetworkReply::NetworkError)
{
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    QMessageBox::critical(this, "Erreur", "Erreur lors du chargement. V√©rifiez votre connexion internet ou ressayez plus tard <br /><br /> Code de l'erreur : <br /><em>" + r->errorString() + "</em>");
    close();
}

void ImportDialog::progressionDownload(qint64 bytesReceived, qint64 bytesTotal)
{
    if (bytesTotal != -1)
    {
        ui->progressBar->setRange(0, bytesTotal);
        ui->progressBar->setValue(bytesReceived);
    }
}

void ImportDialog::on_pushBtWeb_clicked()
{
    telechargement();
}


void ImportDialog::on_buttonBox_accepted()
{
    /* TODO
      Copier les images depuis le dossier d'import
      Copier les images depuis le web et changer les liens dans image_file
      */
    myMem.listSequence.append(listSeq);
}

void ImportDialog::on_pushBtChoose_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("S√©lectionner le r√©pertoire contenant les fichiers "),QString(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    QList<Sequence> listSq = Util::retrieveSeqFiles(dir + "/" + Util::folderSequence);

    Sequence sq;
    foreach(sq,listSq){
        listSeq.append(&sq);
    }

    ui->label_3->setText(listSeq.count() + " s√©quences √  importer");
}
