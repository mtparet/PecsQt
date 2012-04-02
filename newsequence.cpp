#include "newsequence.h"
#include "ui_newsequence.h"
#include "util.h"
#include <QFileDialog>
#include "memory.h"
#include "global.h"

NewSequence::NewSequence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewSequence)
{
    ui->setupUi(this);
}

NewSequence::~NewSequence()
{
    delete ui;
}

void NewSequence::on_pushButton_clicked()
{
    fileList = QFileDialog::getOpenFileNames(this, "Sélectionner les images", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    ui->label_2->setText(QString::number(fileList.count()) + " images choisies");
}

void NewSequence::on_buttonBox_accepted()
{
    Util::saveFiles(fileList);
    QString str;
    foreach(str, fileList){
        mapOrder.insert(str,4);
    }

    Sequence sq = Util::createSequence(mapOrder,name);
    myMem.listSequence << sq;
}

void NewSequence::on_lineEdit_textEdited(const QString &arg1)
{
    name = arg1;
}
