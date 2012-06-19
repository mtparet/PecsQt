#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsequence.h"
#include "sequence.h"
#include "widgetinselector.h"
#include "globval.h"
#include "util.h"
#include "organizedialog.h"
#include "apiparse.h"
#include "importdialog.h"
#include "imagewidget.h"
#include "imageseqmodel.h"
#include "imagereceptordelegate.h"
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    /* menu */

    // Creating a menu "File"
    QMenu* menuFile = new QMenu("Fichier");

    // And adding the menu "File" in the menu bar
    ui->menuBar->addMenu(menuFile);

    // Now we add our items
    // Add an item "Open"
    menuFile->addAction(QString("Nouvelle sequence"), this, SLOT(open_newsequence()));

    // Add a separator
    menuFile->addSeparator();
    menuFile->addAction(QString("Organiser les séquences"), this, SLOT(open_organizesequence()));
    menuFile->addSeparator();

    menuFile->addAction(QString("exporter"), this, SLOT(open_export()));
    menuFile->addSeparator();

    menuFile->addAction(QString("importer"), this, SLOT(open_import()));
    menuFile->addSeparator();

    // Add an item "Bye" connected to the slot  "close" of the mainWindow
    menuFile->addAction("Quitter", this, SLOT(close()) );

    /* ---- */


    refreshData();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshData(){
    QSize *size = myMem.size_in_widget;
    updateListSequenceInSelector(myMem.listSequence,size);


    QWidget *viewport = new QWidget;
    viewport->setLayout(ui->horizontalLayout_selector);

    ui->scrollArea->setWidget(viewport);

    if(!myMem.listSequence.isEmpty()){
        Sequence *sq = myMem.listSequence.first();
        selectOneSequence(sq);
    }


}

void MainWindow::selectOneSequence(Sequence *seq){
    seqDelegate = new ImageReceptorDelegate(this, myMem.size_in_view);

    selectSeq = new Sequence(seq);

    initLayoutSequence();

    buildLayoutReceptor();

}

void MainWindow::selectedSequence(Sequence *f){
    selectOneSequence(f);
}


void MainWindow::updateListSequenceInSelector(QList<Sequence*> listSeq,QSize *size){

    ui->horizontalLayout_selector = new QHBoxLayout(ui->centralWidget);
    Sequence seq;
    foreach(seq,listSeq){
        widgetInSelector *mylistSelector = new widgetInSelector(ui->centralWidget,&seq,size);
        connect(mylistSelector, SIGNAL(setSequence(Sequence *)), this, SLOT(selectedSequence(Sequence*)));
        ui->horizontalLayout_selector->addWidget(mylistSelector);
    }
}

void MainWindow::buildLayoutReceptor(){

    Sequence *sequence_vide = new Sequence();

    for(int i = 0; i < selectSeq.listImageInSequence.length(); i++){
        ImageInSequence is;
        is.img.image_file = "null";
        sequence_vide->listImageInSequence.append(is);
    }

    sequenceReceptor = new ImageSeqModel(this,sequence_vide,true);

    ui->listView->setItemDelegate(seqDelegate);
    ui->listView->setModel(sequenceReceptor);

    ui->listView->setDragEnabled(true);
    ui->listView->setAcceptDrops(true);
    ui->listView->setDropIndicatorShown(true);

}

void MainWindow::initLayoutSequence(){

    ImageSeqModel *seqModel = new ImageSeqModel(this,&selectSeq,false);
    ui->listView_2->reset();

    ui->listView_2->setItemDelegate(seqDelegate);

    ui->listView_2->setModel(seqModel);

    ui->listView_2->setDragEnabled(true);
    ui->listView_2->setAcceptDrops(true);
    ui->listView_2->setDropIndicatorShown(true);
}



void MainWindow::open_newsequence()
{
    NewSequence *newSequence = new NewSequence(this);
    connect(newSequence, SIGNAL(updateUi()), this, SLOT(updateUi()));
    newSequence->show();
}

void MainWindow::open_organizesequence()
{
    OrganizeDialog *newSequence = new OrganizeDialog(this);
    connect(newSequence, SIGNAL(updateMainWindows()), this, SLOT(updateUi()));
    newSequence->show();
}

void MainWindow::open_export()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Sélectionner le répertoire contenant les fichiers "),QString(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    Util::extractRessources(dir);
}

void MainWindow::open_import()
{
    ImportDialog *importDialog = new ImportDialog(this);
    importDialog->show();
}

void MainWindow::updateUi(){
    this->refreshData();
}


void MainWindow::on_zoom_in_clicked()
{
    myMem.size_in_widget = new QSize(myMem.size_in_widget->width() + 5, myMem.size_in_widget->height() + 5);

    QSize *size = myMem.size_in_widget;
    updateListSequenceInSelector(myMem.listSequence, size);
    QWidget *viewport = new QWidget;
    viewport->setLayout(ui->horizontalLayout_selector);

    ui->scrollArea->setWidget(viewport);

    //---
    myMem.size_in_view = new QSize(myMem.size_in_view->width() + 5, myMem.size_in_view->height() + 5);
    QSize *size_view = myMem.size_in_view;

    seqDelegate->setSize(size_view);
    ui->listView->repaint();
    ui->listView_2->repaint();
}

void MainWindow::on_zoom_out_clicked()
{
    myMem.size_in_widget = new QSize(myMem.size_in_widget->width() - 5, myMem.size_in_widget->height() - 5);

    QSize *size = myMem.size_in_widget;
    updateListSequenceInSelector(myMem.listSequence, size);
    QWidget *viewport = new QWidget;
    viewport->setLayout(ui->horizontalLayout_selector);

    ui->scrollArea->setWidget(viewport);

    myMem.size_in_view = new QSize(myMem.size_in_view->width() - 5, myMem.size_in_view->height() - 5);

    QSize *size_view = myMem.size_in_view;

    seqDelegate->setSize(size_view);
    qApp->processEvents();
    ui->listView->repaint();
    ui->listView_2->repaint();
}
