#include "mybaselistwidget.h"
#include "util.h"

MyBaseListWidget::MyBaseListWidget(QWidget *parent) :
    QListWidget(parent)
{
    QSize *image_size = new QSize(100,100);
    this->setIconSize(*image_size);
    this->setMaximumHeight(image_size->height()+10);
    this->setGridSize(*image_size);
}

void MyBaseListWidget::addImage(QString name,QIcon image, int order){
    QIcon *icon = new QIcon(image);
    QListWidgetItem *a = new QListWidgetItem(QString::number(order));
    a->setIcon(*icon);
    this->addItem(a);

}


void MyBaseListWidget::chargeListImageInsequence(QList<ImageInSequence> listImg){
    this->clear();
    ImageInSequence imgSeq;
    foreach(imgSeq,listImg){
        this->addImage(imgSeq.img.name,Util::getIcon(imgSeq.img.image_file),imgSeq.orderIn);
    }
}
