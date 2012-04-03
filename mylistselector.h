#ifndef MYLISTSELECTOR_H
#define MYLISTSELECTOR_H

#include "mybaselistwidget.h"


class MListSelector : public MyBaseListWidget
{
    Q_OBJECT
public:
    explicit MListSelector(QWidget *parent = 0);

protected:
    QSize *qs;

signals:

public slots:
};

#endif // MYLISTSELECTOR_H
