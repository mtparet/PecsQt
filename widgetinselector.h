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
    explicit widgetInSelector(QWidget *parent = 0, Sequence *f = 0);
    ~widgetInSelector();
    
private:
    Ui::widgetInSelector *ui;
    Sequence *myS;
};

#endif // WIDGETINSELECTOR_H
