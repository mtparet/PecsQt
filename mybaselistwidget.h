#ifndef MYBASELISTWIDGET_H
#define MYBASELISTWIDGET_H
#include <QListWidget>
#include "imageinsequence.h"

class MyBaseListWidget: public QListWidget
{
    Q_OBJECT
public:
    explicit MyBaseListWidget(QWidget *parent = 0);
    void chargeListImageInsequence(QList<ImageInSequence> listImg);
    void addImage(QString name,QIcon image, int order);
    void setSizeIcon(QSize image_size);


protected:
    QSize *image_size;

signals:

public slots:
};

#endif // MYBASELISTWIDGET_H
