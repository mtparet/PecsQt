#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sequence.h"
#include "imagewidget.h"
#include "imageseqmodel.h"
#include "imagereceptordelegate.h"

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
        void selectedSequence(Sequence *f);
    
private slots:
    void open_newsequence();
    void open_organizesequence();
    void open_export();
    void open_import();
    void on_zoom_in_clicked();
    void on_zoom_out_clicked();

private:
    Ui::MainWindow *ui;

    void updateListSequenceInSelector(QList<Sequence*> listSeq,QSize *size);
    void buildLayoutReceptor();
    void initLayoutSequence();
    void selectOneSequence(Sequence *seq);

    Sequence selectSeq;

    //tableau des images déj  mise, le nom de leur fichier est pris en compte
    ImageSeqModel *sequenceReceptor;
    QList<ImageWIdget*> listImageWidget;
    ImageReceptorDelegate *seqDelegate;

};

#endif // MAINWINDOW_H
