#include "mylistwidget.h"
#include <QDebug>

MyListWidget::MyListWidget(QWidget *parent) :
   MyBaseListWidget(parent)
{
    setDragDropMode(QAbstractItemView::DragDrop);
    setDefaultDropAction(Qt::MoveAction);
    setFlow(QListView::LeftToRight);
    setAlternatingRowColors(true);
}

void MyListWidget::dropEvent(QDropEvent *event)
{
    qDebug() << "This is my custom dropEvent() method!";
    QListWidget::dropEvent(event);
}
