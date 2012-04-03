#include "editordersequence.h"
#include "ui_editordersequence.h"

EditOrderSequence::EditOrderSequence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditOrderSequence)
{
    ui->setupUi(this);
}

EditOrderSequence::~EditOrderSequence()
{
    delete ui;
}
