#ifndef ORGANIZEDIALOG_H
#define ORGANIZEDIALOG_H

#include <QDialog>
#include "onereorganizewidget.h"

namespace Ui {
class OrganizeDialog;
}

class OrganizeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OrganizeDialog(QWidget *parent = 0);
    ~OrganizeDialog();

public slots:
   void removeMe(OneReorganizeWidget *one);
    
private slots:
   void on_buttonBox_accepted();

signals:
   void updateMainWindows();

private:
    Ui::OrganizeDialog *ui;
    void chargeListSequenceInSelector(QList<Sequence*> listSeq);

};

#endif // ORGANIZEDIALOG_H
