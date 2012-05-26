#include "mylistselector.h"

MyListSelector::MyListSelector(QWidget *parent): MyBaseListWidget(parent)
{
 setDragEnabled(false);
 setFlow(QListView::LeftToRight);
 image_size= new QSize(30,30);
 setSizeIcon(*image_size);

}
