#include "imagereceptordelegate.h"
#include "QPainter"
#include "imageinsequence.h"
#include "util.h"
#include <iostream>

ImageReceptorDelegate::ImageReceptorDelegate(QWidget *parent,QSize *size) : QStyledItemDelegate(parent) {
this->size = size;
}

void ImageReceptorDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const{


    QVariantMap  variantMap = index.data(Qt::DisplayRole).toMap();

     QVariant isVariant = variantMap["li"];
     int right = variantMap["left"].toInt();
     int left = variantMap["right"].toInt();

    ImageInSequence is;
    is.fromVariant(isVariant.toMap());

    //painter->save();

    QColor color;
    if(right == 2 && left == 2){
        color = Qt::red;
    }else if(right == 1 && left == 1){
        color = Qt::green;
    }else if(right == 1 || left == 1){
        color = Qt::yellow;
    }else{
         color = Qt::black;
    }


    QPen pen =  QPen(Qt::SolidPattern);
    pen.setWidth(5);
    pen.setColor(color);

    painter->setPen(pen);

    painter->drawRect(index.row()*size->width(), 0, size->width() - 8, size->height() + 10);

    std::cout << "DELGATE " <<  "image_file:" << is.img.image_file.toStdString() << " folder:" << is.folder.toStdString() << std::endl;

    QPixmap image = Util::getPixmapFile(is.img.image_file,is.folder);

    //TODO externaliser les valeurs pour povoir mettre un zoom
    painter->drawPixmap(index.row()*size->width(),10,size->width() - 10,size->width(),image);


    //painter->restore();
}

QSize ImageReceptorDelegate::sizeHint(const QStyleOptionViewItem &option,
                const QModelIndex &index) const{
    return QSize(100, 120);
}

void ImageReceptorDelegate::setSize(QSize *size){
    this->size = size;
}


