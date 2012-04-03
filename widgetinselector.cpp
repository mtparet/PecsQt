#include "widgetinselector.h"
#include "ui_widgetinselector.h"

widgetInSelector::widgetInSelector(QWidget *parent,Sequence *f) :
    QWidget(parent),
    ui(new Ui::widgetInSelector)
{
    ui->setupUi(this);
    ui->label->setText(f->name);
    ui->listWidget->chargeListImageInsequence(f->listImageInSequence);
}

widgetInSelector::~widgetInSelector()
{
    delete ui;
}
