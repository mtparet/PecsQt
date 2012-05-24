#ifndef MYBASELISTVIEW_H
#define MYBASELISTVIEW_H

#include <QListView>

class MyBaseListView : public QListView
{
    Q_OBJECT
public:
    explicit MyBaseListView(QWidget *parent = 0);
protected:
    void dropEvent(QDropEvent *event);
    
signals:
    
public slots:
    
};

#endif // MYBASELISTVIEW_H
