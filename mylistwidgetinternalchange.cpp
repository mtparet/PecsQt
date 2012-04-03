#include "mylistwidgetinternalchange.h"

MyListWidgetInternalChange::MyListWidgetInternalChange(QWidget *parent) :
    MyBaseListWidget(parent)
{
    this->setDragDropMode(QAbstractItemView::InternalMove);
    this->setFlow(QListView::LeftToRight);
}
