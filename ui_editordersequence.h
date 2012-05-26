/********************************************************************************
** Form generated from reading UI file 'editordersequence.ui'
**
** Created by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORDERSEQUENCE_H
#define UI_EDITORDERSEQUENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include "mylistwidgetinternalchange.h"

QT_BEGIN_NAMESPACE

class Ui_EditOrderSequence
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    MyListWidgetInternalChange *listWidget;
    QLabel *label_2;

    void setupUi(QDialog *EditOrderSequence)
    {
        if (EditOrderSequence->objectName().isEmpty())
            EditOrderSequence->setObjectName(QString::fromUtf8("EditOrderSequence"));
        EditOrderSequence->resize(958, 497);
        buttonBox = new QDialogButtonBox(EditOrderSequence);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(570, 440, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(EditOrderSequence);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 20, 201, 31));
        label = new QLabel(EditOrderSequence);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 141, 31));
        listWidget = new MyListWidgetInternalChange(EditOrderSequence);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 190, 931, 181));
        label_2 = new QLabel(EditOrderSequence);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 160, 221, 21));

        retranslateUi(EditOrderSequence);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditOrderSequence, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditOrderSequence, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditOrderSequence);
    } // setupUi

    void retranslateUi(QDialog *EditOrderSequence)
    {
        EditOrderSequence->setWindowTitle(QApplication::translate("EditOrderSequence", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EditOrderSequence", "Nom de la s\303\251quence :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EditOrderSequence", "Modifier l'ordre de la s\303\251quence :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditOrderSequence: public Ui_EditOrderSequence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORDERSEQUENCE_H
