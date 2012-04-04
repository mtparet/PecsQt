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
    this->f = f;
    ui->listWidget->chargeListImageInsequence(f->listImageInSequence);
}

OneReorganizeWidget::~OneReorganizeWidget()
{
    delete ui;
}

void OneReorganizeWidget::on_EditerButton_clicked()
{
    EditOrderSequence *editOrder = new EditOrderSequence(this,f);
    editOrder->show();
}

void OneReorganizeWidget::on_RemoveButton_clicked()
{
    Util::removeOneSeq(*f);
    //myMem.listSequence.removeOne(*f);
    removeMe(this);

}
