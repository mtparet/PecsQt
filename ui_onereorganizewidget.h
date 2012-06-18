/********************************************************************************
** Form generated from reading UI file 'onereorganizewidget.ui'
**
** Created: Mon 18. Jun 14:32:05 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEREORGANIZEWIDGET_H
#define UI_ONEREORGANIZEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "mylistselector.h"

QT_BEGIN_NAMESPACE

class Ui_OneReorganizeWidget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    MyListSelector *listWidget;
    QSpacerItem *horizontalSpacer;
    QPushButton *EditerButton;
    QPushButton *RemoveButton;

    void setupUi(QWidget *OneReorganizeWidget)
    {
        if (OneReorganizeWidget->objectName().isEmpty())
            OneReorganizeWidget->setObjectName(QString::fromUtf8("OneReorganizeWidget"));
        OneReorganizeWidget->resize(776, 116);
        horizontalLayoutWidget = new QWidget(OneReorganizeWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 761, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new MyListSelector(horizontalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        EditerButton = new QPushButton(horizontalLayoutWidget);
        EditerButton->setObjectName(QString::fromUtf8("EditerButton"));

        horizontalLayout->addWidget(EditerButton);

        RemoveButton = new QPushButton(horizontalLayoutWidget);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));

        horizontalLayout->addWidget(RemoveButton);


        retranslateUi(OneReorganizeWidget);

        QMetaObject::connectSlotsByName(OneReorganizeWidget);
    } // setupUi

    void retranslateUi(QWidget *OneReorganizeWidget)
    {
        OneReorganizeWidget->setWindowTitle(QApplication::translate("OneReorganizeWidget", "Form", 0, QApplication::UnicodeUTF8));
        EditerButton->setText(QApplication::translate("OneReorganizeWidget", "Editer", 0, QApplication::UnicodeUTF8));
        RemoveButton->setText(QApplication::translate("OneReorganizeWidget", "Supprimer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OneReorganizeWidget: public Ui_OneReorganizeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEREORGANIZEWIDGET_H
