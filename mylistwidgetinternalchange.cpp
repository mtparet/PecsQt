#include "mylistwidgetinternalchange.h"
#include "globval.h"

MyListWidgetInternalChange::MyListWidgetInternalChange(QWidget *parent) :
    MyBaseListWidget(parent)
{
    QSize *size_view = myMem.size_in_view;
    setIconSize(*size_view);
    this->setDragDropMode(QAbstractItemView::InternalMove);
    this->setFlow(QListView::LeftToRight);
}
