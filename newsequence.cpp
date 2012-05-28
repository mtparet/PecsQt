#include "newsequence.h"
#include "ui_newsequence.h"
#include "util.h"
#include <QFileDialog>
#include "memory.h"
#include "globval.h"
#include "editordersequence.h"

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
    Util::saveImageFiles(fileList, name);
    QStringList listeName = Util::getFileName(fileList);

    sq.fromQMap(listeName,name);
    myMem.add(sq);

    EditOrderSequence *editOrder = new EditOrderSequence(this,&sq);
    connect(editOrder, SIGNAL(updateNewSeq()), this, SLOT(updateNewSeq()));
    editOrder->show();
}

void NewSequence::on_lineEdit_textEdited(const QString &arg1)
{
    name = arg1;
}

void NewSequence::updateNewSeq(){
    this->updateUi();
}
