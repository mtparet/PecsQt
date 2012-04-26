#ifndef CASEWIDGET_H
#define CASEWIDGET_H

#include <QWidget>
#include "imageinsequence.h"

namespace Ui {
class CaseWidget;
}

class CaseWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CaseWidget(QWidget *parent = 0, ImageInSequence *imS = 0, int placeE = 0, QString *folder = 0);

    ~CaseWidget();
signals:
   void updateReceptor(QString id_name,int num_place,QString name,bool present);
   void updateLayoutSequence(QString name,bool present);
public slots:
    void makeDrag();
protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::CaseWidget *ui;
    ImageInSequence myS;
    int place;
    QPoint dragStartPosition;
};

#endif // CASEWIDGET_H
