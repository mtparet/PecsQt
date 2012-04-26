#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include "imageinsequence.h"

namespace Ui {
    class ImageWIdget;
}

class ImageWIdget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageWIdget(QWidget *parent = 0, ImageInSequence *imS = 0, int placeE = 0, QString *folder = 0);
    ImageInSequence myS;
    void changeImage(bool present);
    ~ImageWIdget();
public slots:
    void makeDrag();
protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::ImageWIdget *ui;
    QString myFolder;

    int place;
    QPoint dragStartPosition;
};

#endif // IMAGEWIDGET_H
