#include "mybaselistview.h"

MyBaseListView::MyBaseListView(QWidget *parent) :
    QListView(parent)
{
}

void MyBaseListView::dropEvent(QDropEvent *event){
    QListView::dropEvent(event);
}
