#ifndef IMAGERECEPTORDELEGATE_H
#define IMAGERECEPTORDELEGATE_H
#include <QStyledItemDelegate>

class ImageReceptorDelegate : public QStyledItemDelegate
{
public:
    explicit ImageReceptorDelegate(QWidget *parent = 0,QSize *size = 0);
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    QSize sizeHint(const QStyleOptionViewItem &option,
                    const QModelIndex &index) const;
    void setSize(QSize *size);
private:
    QSize *size;
};

#endif // IMAGERECEPTORDELEGATE_H
