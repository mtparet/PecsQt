#ifndef MYLISTWIDGETRECEPTOR_H
#define MYLISTWIDGETRECEPTOR_H

#include <QListWidget>

class MyListWidgetReceptor : public QListWidget
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
