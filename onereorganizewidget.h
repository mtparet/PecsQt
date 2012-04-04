#ifndef ONEREORGANIZEWIDGET_H
#define ONEREORGANIZEWIDGET_H

#include <QWidget>
#include "sequence.h"

namespace Ui {
class OneReorganizeWidget;
}

class OneReorganizeWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit OneReorganizeWidget(QWidget *parent = 0, Sequence *f = 0);
    ~OneReorganizeWidget();
signals:
   void removeMe(OneReorganizeWidget *one);

private slots:
    void on_EditerButton_clicked();

    void on_RemoveButton_clicked();

private:
    Ui::OneReorganizeWidget *ui;
    Sequence *myS;
};

#endif // ONEREORGANIZEWIDGET_H
