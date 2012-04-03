#ifndef MYLISTWIDGETRECEPTOR_H
#define MYLISTWIDGETRECEPTOR_H

#include "mybaselistwidget.h"


class MyListWidgetReceptor : public MyBaseListWidget
{
    Q_OBJECT
public:
    explicit MyListWidgetReceptor(QWidget *parent = 0);
protected:
    void dropEvent(QDropEvent *event);
    
signals:
    
public slots:
    
};

#endif // MYLISTWIDGETRECEPTOR_H
