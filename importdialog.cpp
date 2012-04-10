#include "importdialog.h"
#include "ui_importdialog.h"
#include <QMessageBox>
#include "apiparse.h"
#include "globval.h"
#include "memory.h"

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
    json = r->readAll();
    //f.write(r->readAll()); ////On lit la rponse du serveur que l'on met dans un fichier
    //f.close(); //On ferme le fichier
    //r->deleteLater(); //IMPORTANT : on emploie la fonction deleteLater() pour supprimer la rponse du serveur.
    //Si vous ne le faites pas, vous risquez des fuites de mmoire ou autre.

    QMessageBox::information(this, "Fin de téléchargement", "téléchargement terminé !"); //On indique que tout s'est bien pass
}

void ImportDialog::messageErreur(QNetworkReply::NetworkError)
{
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    QMessageBox::critical(this, "Erreur", "Erreur lors du chargement. Vrifiez votre connexion internet ou ressayez plus tard <br /><br /> Code de l'erreur : <br /><em>" + r->errorString() + "</em>");
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
    QList<Sequence> f = ApiParse::parseListFromROR(json);
    myMem.listSequence.append(f);
}
