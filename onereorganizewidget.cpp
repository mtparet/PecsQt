#include "onereorganizewidget.h"
#include "ui_onereorganizewidget.h"
#include "mylistselector.h"
#include "editordersequence.h"
#include "util.h"
#include "globval.h"

OneReorganizeWidget::OneReorganizeWidget(QWidget *parent,Sequence *f) :
    QWidget(parent),
    ui(new Ui::OneReorganizeWidget)
{
    ui->setupUi(this);
    this->myS = new Sequence(f);
    ui->listWidget->chargeListImageInsequence(myS, true,f->listImageInSequence.count());
}

OneReorganizeWidget::~OneReorganizeWidget()
{
    delete ui;
}

void OneReorganizeWidget::on_EditerButton_clicked()
{
    EditOrderSequence *editOrder = new EditOrderSequence(this,myS);
    editOrder->show();
}

void OneReorganizeWidget::on_RemoveButton_clicked()
{
    Util::removeSeqFile(myS);
    myMem.remove(myS);
    removeMe(this);

}
