/********************************************************************************
** Form generated from reading UI file 'casewidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CASEWIDGET_H
#define UI_CASEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaseWidget
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;

    void setupUi(QWidget *CaseWidget)
    {
        if (CaseWidget->objectName().isEmpty())
            CaseWidget->setObjectName(QString::fromUtf8("CaseWidget"));
        CaseWidget->resize(177, 233);
        graphicsView = new QGraphicsView(CaseWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(40, 10, 101, 81));
        label = new QLabel(CaseWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 151, 111));

        retranslateUi(CaseWidget);

        QMetaObject::connectSlotsByName(CaseWidget);
    } // setupUi

    void retranslateUi(QWidget *CaseWidget)
    {
        CaseWidget->setWindowTitle(QApplication::translate("CaseWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CaseWidget: public Ui_CaseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CASEWIDGET_H
