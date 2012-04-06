#ifndef CASEWIDGET_H
#define CASEWIDGET_H

#include <QWidget>
#include "imageinsequence.h"

namespace Ui {
class CaseWidget;
}

class CaseWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CaseWidget(QWidget *parent = 0, ImageInSequence *imS = 0, int placeE = 0, QString *folder = 0);

    ~CaseWidget();
    
private:
    Ui::CaseWidget *ui;
    ImageInSequence myS;
    int place;
};

#endif // CASEWIDGET_H
