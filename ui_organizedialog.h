/********************************************************************************
** Form generated from reading UI file 'organizedialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORGANIZEDIALOG_H
#define UI_ORGANIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrganizeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *OrganizeDialog)
    {
        if (OrganizeDialog->objectName().isEmpty())
            OrganizeDialog->setObjectName(QString::fromUtf8("OrganizeDialog"));
        OrganizeDialog->resize(883, 427);
        buttonBox = new QDialogButtonBox(OrganizeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(530, 390, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        scrollArea = new QScrollArea(OrganizeDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(9, 9, 861, 371));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 857, 367));
        scrollArea->setWidget(scrollAreaWidgetContents);
        verticalLayoutWidget = new QWidget(OrganizeDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(540, 390, 131, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(OrganizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OrganizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OrganizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OrganizeDialog);
    } // setupUi

    void retranslateUi(QDialog *OrganizeDialog)
    {
        OrganizeDialog->setWindowTitle(QApplication::translate("OrganizeDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OrganizeDialog: public Ui_OrganizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZEDIALOG_H
