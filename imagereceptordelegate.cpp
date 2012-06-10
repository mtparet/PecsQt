#include "imagereceptordelegate.h"
#include "QPainter"
#include "imageinsequence.h"
#include "util.h"
#include <iostream>

ImageReceptorDelegate::ImageReceptorDelegate(QWidget *parent ) : QStyledItemDelegate(parent) {}

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

    painter->drawRect(index.row()*100, 0, 92, 110);

    std::cout << "DELGATE " <<  "image_file:" << is.img.image_file.toStdString() << " folder:" << is.folder.toStdString() << std::endl;

    QPixmap image = Util::getPixmapFile(is.img.image_file,is.folder);
    painter->drawPixmap(index.row()*100,10,90,100,image);


    //painter->restore();
}

QSize ImageReceptorDelegate::sizeHint(const QStyleOptionViewItem &option,
                const QModelIndex &index) const{
    return QSize(100, 120);
}

