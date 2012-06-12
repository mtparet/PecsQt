#ifndef MYBASELISTWIDGET_H
#define MYBASELISTWIDGET_H
#include <QListWidget>
#include "imageinsequence.h"
#include "sequence.h"

class MyBaseListWidget: public QListWidget
{
    Q_OBJECT
public:
    explicit MyBaseListWidget(QWidget *parent = 0);
    void chargeListImageInsequence(Sequence sq, bool sorted, int nb_image_charge);
    void addImage(QString name,QIcon image);
    void setSizeIcon(QSize *image_size);


protected:
    QSize *image_size;

signals:

public slots:
};

#endif // MYBASELISTWIDGET_H
