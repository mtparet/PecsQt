#include "mylistselector.h"
#include "globval.h"

MyListSelector::MyListSelector(QWidget *parent): MyBaseListWidget(parent)
{
 setDragEnabled(false);
 setFlow(QListView::LeftToRight);
 setMinimumWidth(100);
 setFixedHeight(140);
 setSelectionMode(QAbstractItemView::NoSelection);

}

void MyListSelector::mousePressEvent(QMouseEvent *event){
    emit setSequence();
}

