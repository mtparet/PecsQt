#include "mybaselistwidget.h"
#include "imageinsequence.h"
#include "util.h"
#include <QDebug>
#include <globval.h>

MyBaseListWidget::MyBaseListWidget(QWidget *parent) :
    QListWidget(parent)
{

}

void MyBaseListWidget::setSizeIcon(QSize *image_size2)
{
    this->image_size = image_size2;
    this->setIconSize(*image_size);
    this->setMaximumHeight(image_size->height()+8);
    this->setGridSize(*image_size);
}

void MyBaseListWidget::addImage(QString name,QIcon image){
    QIcon *icon = new QIcon(image);
    QListWidgetItem *a = new QListWidgetItem("");
   // a->setSizeHint(*image_size);
    a->setData(31,name);
    a->setIcon(*icon);
    this->addItem(a);

}


void MyBaseListWidget::chargeListImageInsequence(Sequence sq, bool sorted, int nb_image_charge){

    this->clear();
    QList<ImageInSequence> listImg = sq.listImageInSequence;

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
    int i = 0;
    while(i < listImg.count() && i < nb_image_charge){
        ImageInSequence imgSeq = listImg.at(i);
        this->addImage(imgSeq.img.name,Util::getIcon(imgSeq.img.image_file, sq.name));
        ++i;
    }
}
