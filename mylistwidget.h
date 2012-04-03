#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include "mybaselistwidget.h"

class MyListWidget : public MyBaseListWidget
{
    Q_OBJECT
public:
    explicit MyListWidget(QWidget *parent = 0);

protected:
    void dropEvent(QDropEvent *event);
    
signals:
    
public slots:
    
};

#endif // MYLISTWIDGET_H
