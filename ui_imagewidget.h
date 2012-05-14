/********************************************************************************
** Form generated from reading UI file 'imagewidget.ui'
**
** Created: Sat May 5 14:54:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIDGET_H
#define UI_IMAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageWIdget
{
public:
    QLabel *label;

    void setupUi(QWidget *ImageWIdget)
    {
        if (ImageWIdget->objectName().isEmpty())
            ImageWIdget->setObjectName(QString::fromUtf8("ImageWIdget"));
        ImageWIdget->resize(200, 136);
        label = new QLabel(ImageWIdget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 161, 101));

        retranslateUi(ImageWIdget);

        QMetaObject::connectSlotsByName(ImageWIdget);
    } // setupUi

    void retranslateUi(QWidget *ImageWIdget)
    {
        ImageWIdget->setWindowTitle(QApplication::translate("ImageWIdget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageWIdget: public Ui_ImageWIdget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIDGET_H
