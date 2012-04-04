#include "widgetinselector.h"
#include "ui_widgetinselector.h"

widgetInSelector::widgetInSelector(QWidget *parent,Sequence *f) :
    QWidget(parent),
    ui(new Ui::widgetInSelector)
{
    ui->setupUi(this);
    myS = new Sequence(f);
    ui->label->setText(myS->name);
    ui->listWidget->chargeListImageInsequence(myS->listImageInSequence, false);
}

widgetInSelector::~widgetInSelector()
{
    delete ui;
}
