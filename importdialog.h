#ifndef IMPORTDIALOG_H
#define IMPORTDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class ImportDialog;
}

class ImportDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImportDialog(QWidget *parent = 0);
    ~ImportDialog();
    
private:
    Ui::ImportDialog *ui;
    QByteArray json;

private slots:
    void telechargement();
    void messageErreur(QNetworkReply::NetworkError);
    void afficher();
    void progressionDownload(qint64 bytesReceived, qint64 bytesTotal);

    void on_pushBtWeb_clicked();
    void on_buttonBox_accepted();
};

#endif // IMPORTDIALOG_H
