#ifndef WIDGETINSELECTOR_H
#define WIDGETINSELECTOR_H

#include <QWidget>
#include "mylistselector.h"
#include "sequence.h"

namespace Ui {
class widgetInSelector;
}

class widgetInSelector : public QWidget
{
    Q_OBJECT
public:
    explicit widgetInSelector(QWidget *parent = 0, Sequence *f = 0,QSize *size = 0);
    ~widgetInSelector();

public slots:
     void selectedSequence();

signals :
        void setSequence(Sequence *f);

private:
    Ui::widgetInSelector *ui;
    Sequence *myS;
    void mousePressEvent(QMouseEvent *event);

};

#endif // WIDGETINSELECTOR_H
