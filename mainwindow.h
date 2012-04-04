#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sequence.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void refreshData();
    ~MainWindow();

public slots:
        void updateUi();
    
private slots:
    void open_newsequence();
    void open_organizesequence();



private:
    Ui::MainWindow *ui;
    void chargeListSequenceInSelector(QList<Sequence> listSeq);
    Sequence selectSeq;

};

#endif // MAINWINDOW_H
