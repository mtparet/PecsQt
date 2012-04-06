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
    void open_export();
    void open_import();





private:
    Ui::MainWindow *ui;
    void chargeListSequenceInSelector(QList<Sequence> listSeq);
    void initLayoutReceptor(Sequence sq);

    Sequence selectSeq;

};

#endif // MAINWINDOW_H
