/********************************************************************************
** Form generated from reading UI file 'importdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTDIALOG_H
#define UI_IMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ImportDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushBtWeb;
    QLabel *label_2;
    QPushButton *pushBtChoose;
    QProgressBar *progressBar;
    QLabel *label_3;

    void setupUi(QDialog *ImportDialog)
    {
        if (ImportDialog->objectName().isEmpty())
            ImportDialog->setObjectName(QString::fromUtf8("ImportDialog"));
        ImportDialog->resize(413, 341);
        buttonBox = new QDialogButtonBox(ImportDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 300, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(ImportDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 100, 113, 25));
        label = new QLabel(ImportDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 100, 101, 21));
        pushBtWeb = new QPushButton(ImportDialog);
        pushBtWeb->setObjectName(QString::fromUtf8("pushBtWeb"));
        pushBtWeb->setGeometry(QRect(300, 100, 80, 26));
        label_2 = new QLabel(ImportDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 131, 16));
        pushBtChoose = new QPushButton(ImportDialog);
        pushBtChoose->setObjectName(QString::fromUtf8("pushBtChoose"));
        pushBtChoose->setGeometry(QRect(150, 30, 80, 26));
        progressBar = new QProgressBar(ImportDialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(140, 130, 151, 21));
        progressBar->setValue(0);
        label_3 = new QLabel(ImportDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 210, 181, 16));

        retranslateUi(ImportDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImportDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImportDialog);
    } // setupUi

    void retranslateUi(QDialog *ImportDialog)
    {
        ImportDialog->setWindowTitle(QApplication::translate("ImportDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ImportDialog", "http://127.0.0.1:3000/images_sequentielles.json", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ImportDialog", "Depuis internet:", 0, QApplication::UnicodeUTF8));
        pushBtWeb->setText(QApplication::translate("ImportDialog", "OK", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ImportDialog", "Depuis un fichier:", 0, QApplication::UnicodeUTF8));
        pushBtChoose->setText(QApplication::translate("ImportDialog", "Parcourir...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ImportDialog", "0 s\303\251quence a importer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImportDialog: public Ui_ImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTDIALOG_H
