#ifndef EDITORDERSEQUENCE_H
#define EDITORDERSEQUENCE_H

#include <QDialog>

namespace Ui {
class EditOrderSequence;
}

class EditOrderSequence : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditOrderSequence(QWidget *parent = 0);
    ~EditOrderSequence();
    
private:
    Ui::EditOrderSequence *ui;
};

#endif // EDITORDERSEQUENCE_H
