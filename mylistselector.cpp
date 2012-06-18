#include "mylistselector.h"
#include "globval.h"

MyListSelector::MyListSelector(QWidget *parent): MyBaseListWidget(parent)
{
 setDragEnabled(false);
 setFlow(QListView::LeftToRight);
 setMinimumWidth(100);
 QSize *size_view = myMem.size_in_view;
 setIconSize(*size_view);
 setSelectionMode(QAbstractItemView::NoSelection);

}

void MyListSelector::mousePressEvent(QMouseEvent *event){
    emit setSequence();
}

