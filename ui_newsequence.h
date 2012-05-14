/********************************************************************************
** Form generated from reading UI file 'newsequence.ui'
**
** Created: Sat May 5 14:54:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSEQUENCE_H
#define UI_NEWSEQUENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewSequence
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit;

    void setupUi(QDialog *NewSequence)
    {
        if (NewSequence->objectName().isEmpty())
            NewSequence->setObjectName(QString::fromUtf8("NewSequence"));
        NewSequence->resize(645, 324);
        buttonBox = new QDialogButtonBox(NewSequence);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(270, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NewSequence);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 151, 21));
        pushButton = new QPushButton(NewSequence);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 90, 121, 31));
        label_2 = new QLabel(NewSequence);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 90, 161, 21));
        lineEdit = new QLineEdit(NewSequence);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(180, 20, 131, 31));

        retranslateUi(NewSequence);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewSequence, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewSequence, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewSequence);
    } // setupUi

    void retranslateUi(QDialog *NewSequence)
    {
        NewSequence->setWindowTitle(QApplication::translate("NewSequence", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewSequence", "Nom de la s\303\251quence :", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("NewSequence", "Choisir les images", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewSequence", "Aucune image choisie", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewSequence: public Ui_NewSequence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSEQUENCE_H
