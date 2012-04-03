#include "mylistselector.h"

MListSelector::MListSelector(QWidget *parent): MyBaseListWidget(parent)
{
 setDragEnabled(false);
 setFlow(QListView::LeftToRight);
 setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
 qs= new QSize(30,30);
 setSizeIcon(*qs);

}
