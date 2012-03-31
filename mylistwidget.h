#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>

class MyListWidget : public QListWidget
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
