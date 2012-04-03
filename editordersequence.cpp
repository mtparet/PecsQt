#include "editordersequence.h"
#include "ui_editordersequence.h"
#include "globval.h"


EditOrderSequence::EditOrderSequence(QWidget *parent, Sequence *f) :
    QDialog(parent),
    ui(new Ui::EditOrderSequence)
{
    ui->setupUi(this);
    this->f = f;
    ui->listWidget->chargeListImageInsequence(f->listImageInSequence);
    ui->lineEdit->setText(f->name);
}

EditOrderSequence::~EditOrderSequence()
{
    delete ui;
}

void EditOrderSequence::on_buttonBox_accepted()
{
    QMap<QString,int> orderMap;
    int i = 0;
    for(int i = 0; i < ui->listWidget->count(); i ++){
        orderMap.insert(ui->listWidget->item(i)->data(31).toString(),i);
    }

    f->setOrder(orderMap);
    Sequence s = myMem.listSequence.first();
    s.name;

}
