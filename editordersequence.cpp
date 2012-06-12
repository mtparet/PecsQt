 #include "editordersequence.h"
#include "ui_editordersequence.h"
#include "globval.h"
#include "util.h"


EditOrderSequence::EditOrderSequence(QWidget *parent, Sequence *f) :
    QDialog(parent),
    ui(new Ui::EditOrderSequence)
{
    ui->setupUi(this);
    this->f = new Sequence(f);
    ui->listWidget->chargeListImageInsequence(this->f,true,f->listImageInSequence.count());
    ui->lineEdit->setText(this->f->name);
}

EditOrderSequence::~EditOrderSequence()
{
    delete ui;
}

void EditOrderSequence::on_buttonBox_accepted()
{
    QMap<QString,int> orderMap;
    for(int i = 0; i < ui->listWidget->count(); i ++){
        orderMap.insert(ui->listWidget->item(i)->data(31).toString(),i);
    }

    f->setOrder(orderMap);

    f->name = ui->lineEdit->text();

    myMem.replace(f);

    Util::saveOneSeq(f);
    this->updateNewSeq();

}
