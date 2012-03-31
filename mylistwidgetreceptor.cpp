#include "mylistwidgetreceptor.h"
#include <QDebug>
#include <QDropEvent>

MyListWidgetReceptor::MyListWidgetReceptor(QWidget *parent) :
    QListWidget(parent)
{
    setDragDropMode(QAbstractItemView::DragDrop);
    setDefaultDropAction(Qt::MoveAction);
    setAlternatingRowColors(true);
    setFlow(QListView::LeftToRight);
}

void MyListWidgetReceptor::dropEvent(QDropEvent *event)
{
    qDebug() << "This is my custom dropEvent() method!";
    qDebug() << event->source()->accessibleName().toUtf8();
    QListWidget::dropEvent(event);
}
