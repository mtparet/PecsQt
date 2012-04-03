#ifndef EDITORDERSEQUENCE_H
#define EDITORDERSEQUENCE_H

#include <QDialog>
#include "sequence.h"

namespace Ui {
class EditOrderSequence;
}

class EditOrderSequence : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditOrderSequence(QWidget *parent = 0, Sequence *f = 0);
    ~EditOrderSequence();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::EditOrderSequence *ui;
    Sequence *f;
};

#endif // EDITORDERSEQUENCE_H
