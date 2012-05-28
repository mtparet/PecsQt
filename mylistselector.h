#ifndef MYLISTSELECTOR_H
#define MYLISTSELECTOR_H

#include "mybaselistwidget.h"


class MyListSelector : public MyBaseListWidget
{
    Q_OBJECT
public:
    explicit MyListSelector(QWidget *parent = 0);

protected:
    QSize *qs;

signals :
        void setSequence();

public slots:

private:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYLISTSELECTOR_H
