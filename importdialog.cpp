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
    //QFile f("fichier.txt"); //On ouvre le fichier
    //f.open(QIODevice::WriteOnly);
    QByteArray json = r->readAll();
    //f.write(r->readAll()); ////On lit la rponse du serveur que l'on met dans un fichier
    //f.close(); //On ferme le fichier
    //r->deleteLater(); //IMPORTANT : on emploie la fonction deleteLater() pour supprimer la rponse du serveur.
    //Si vous ne le faites pas, vous risquez des fuites de mmoire ou autre.
    listSeq = ApiParse::parseList(json);
    ui->label_3->setText(listSeq.count() + " séquences à importer");

}

void ImportDialog::messageErreur(QNetworkReply::NetworkError)
{
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    QMessageBox::critical(this, "Erreur", "Erreur lors du chargement. Vérifiez votre connexion internet ou ressayez plus tard <br /><br /> Code de l'erreur : <br /><em>" + r->errorString() + "</em>");
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
    QString dir = QFileDialog::getExistingDirectory(this, tr("Sélectionner le répertoire contenant les fichiers "),QString(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    listSeq = Util::retrieveSeqFiles(dir + "/" + Util::folderSequence);
    ui->label_3->setText(listSeq.count() + " séquences à importer");
}
