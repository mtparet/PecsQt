#include "widgetinselector.h"
#include "ui_widgetinselector.h"

widgetInSelector::widgetInSelector(QWidget *parent,Sequence *f) :
    QWidget(parent),
    ui(new Ui::widgetInSelector)
{
    ui->setupUi(this);
    myS = new Sequence(f);
    ui->label->setText(myS->name);
    ui->listWidget->chargeListImageInsequence(myS, false);
    connect(ui->listWidget,SIGNAL(setSequence()),this,SLOT(selectedSequence()));
}

widgetInSelector::~widgetInSelector()
{
    delete ui;
}


void widgetInSelector::mousePressEvent(QMouseEvent *event){
    emit setSequence(this->myS);
}

void widgetInSelector::selectedSequence(){
    emit setSequence(this->myS);
}

