/********************************************************************************
** Form generated from reading UI file 'widgetinselector.ui'
**
** Created: Sat May 5 15:08:31 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETINSELECTOR_H
#define UI_WIDGETINSELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include "mylistselector.h"

QT_BEGIN_NAMESPACE

class Ui_widgetInSelector
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    MyListSelector *listWidget;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *widgetInSelector)
    {
        if (widgetInSelector->objectName().isEmpty())
            widgetInSelector->setObjectName(QString::fromUtf8("widgetInSelector"));
        widgetInSelector->resize(525, 220);
        widgetInSelector->setMinimumSize(QSize(525, 220));
        widgetInSelector->setMaximumSize(QSize(525, 16777215));
        label = new QLabel(widgetInSelector);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 61, 15));
        label->setMidLineWidth(1);
        horizontalLayoutWidget = new QWidget(widgetInSelector);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 40, 521, 103));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new MyListSelector(horizontalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(471, 101));

        horizontalLayout->addWidget(listWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(widgetInSelector);

        QMetaObject::connectSlotsByName(widgetInSelector);
    } // setupUi

    void retranslateUi(QWidget *widgetInSelector)
    {
        widgetInSelector->setWindowTitle(QApplication::translate("widgetInSelector", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("widgetInSelector", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widgetInSelector: public Ui_widgetInSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETINSELECTOR_H
