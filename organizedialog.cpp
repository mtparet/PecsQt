#include "organizedialog.h"
#include "ui_organizedialog.h"
#include "globval.h"

OrganizeDialog::OrganizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrganizeDialog)
{
    ui->setupUi(this);

    chargeListSequenceInSelector(myMem.listSequence);


    QWidget *viewport = new QWidget;
    viewport->setLayout(ui->verticalLayout);

    ui->scrollArea->setWidget(viewport);
}

OrganizeDialog::~OrganizeDialog()
{
    delete ui;
}

void OrganizeDialog::removeMe(OneReorganizeWidget *one){
    this->layout()->removeWidget(one);
}

void OrganizeDialog::chargeListSequenceInSelector(QList<Sequence> listSeq){

    ui->verticalLayout = new QVBoxLayout (this);
    Sequence seq;
    foreach(seq,listSeq){
        OneReorganizeWidget *myReorganizeWidget = new OneReorganizeWidget(this,&seq);
        ui->verticalLayout->addWidget(myReorganizeWidget);
    }
}
