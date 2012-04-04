#include "mylistselector.h"

MyListSelector::MyListSelector(QWidget *parent): MyBaseListWidget(parent)
{
 setDragEnabled(false);
 setFlow(QListView::LeftToRight);
 setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
 qs= new QSize(30,30);
 setSizeIcon(*qs);

}
