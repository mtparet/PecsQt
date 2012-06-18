/********************************************************************************
** Form generated from reading UI file 'widgetinselector.ui'
**
** Created: Mon 18. Jun 15:03:45 2012
**      by: Qt User Interface Compiler version 4.8.2
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

    void setupUi(QWidget *widgetInSelector)
    {
        if (widgetInSelector->objectName().isEmpty())
            widgetInSelector->setObjectName(QString::fromUtf8("widgetInSelector"));
        widgetInSelector->resize(525, 132);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetInSelector->sizePolicy().hasHeightForWidth());
        widgetInSelector->setSizePolicy(sizePolicy);
        widgetInSelector->setMinimumSize(QSize(525, 100));
        widgetInSelector->setMaximumSize(QSize(525, 220));
        label = new QLabel(widgetInSelector);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 61, 15));
        label->setMidLineWidth(1);
        horizontalLayoutWidget = new QWidget(widgetInSelector);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 521, 103));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new MyListSelector(horizontalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(471, 101));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(listWidget);


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
