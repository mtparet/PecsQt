#include "mybaselistwidget.h"
#include "imageinsequence.h"
#include "util.h"
#include <QDebug>

MyBaseListWidget::MyBaseListWidget(QWidget *parent) :
    QListWidget(parent)
{
    image_size = new QSize(100,100);
    this->setIconSize(*image_size);
    this->setMaximumHeight(image_size->height()+8);
    this->setGridSize(*image_size);
}

void MyBaseListWidget::setSizeIcon(QSize image_size2)
{
    this->image_size = &image_size2;
    this->setIconSize(*image_size);
    this->setMaximumHeight(image_size->height()+8);
    this->setGridSize(*image_size);
}

void MyBaseListWidget::addImage(QString name,QIcon image, int order){
    QIcon *icon = new QIcon(image);
    QListWidgetItem *a = new QListWidgetItem("");
    a->setSizeHint(*image_size);
    a->setData(31,name);
    a->setIcon(*icon);
    this->addItem(a);

}


void MyBaseListWidget::chargeListImageInsequence(QList<ImageInSequence> listImg, bool sorted){
    this->clear();
    if(sorted){
        qSort(listImg.begin(), listImg.end(), ImageInSequence::lessThan);
    }else{
        QList<ImageInSequence> randlistImg;
        while(listImg.count() > 0){
            int nb = listImg.count();
            int rand = Util::random(0,nb);

            randlistImg << listImg.value(rand);
            listImg.removeAt(rand);
        }
        listImg = randlistImg;
    }
    ImageInSequence imgSeq;
    foreach(imgSeq,listImg){
        this->addImage(imgSeq.img.name,Util::getIcon(imgSeq.img.image_file),imgSeq.orderIn);
    }
}
