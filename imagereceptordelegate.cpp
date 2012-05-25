#include "imagereceptordelegate.h"
#include "QPainter"
#include "imageinsequence.h"
#include "util.h"
ImageReceptorDelegate::ImageReceptorDelegate(QWidget *parent ) : QStyledItemDelegate(parent) {}

void ImageReceptorDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const{
    ImageInSequence is;
    is.fromVariant(index.data(Qt::DisplayRole).toMap());

    painter->save();
    QPixmap image = Util::getPixmapFile(is.img.image_file,is.folder);
    painter->drawPixmap(index.row()*90,0,90,90,image);
    painter->restore();
}

QSize ImageReceptorDelegate::sizeHint(const QStyleOptionViewItem &option,
                const QModelIndex &index) const{
    return QSize(90, 90);
}

