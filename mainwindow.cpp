#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsequence.h"
#include "mylistwidget.h"
#include "sequence.h"
#include "widgetinselector.h"
#include "globval.h"
#include "util.h"
#include "organizedialog.h"
#include <QMenu>
#include <QMenuBar>
#include <QLabel>

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
      // Add an item "Bye" connected to the slot  "close" of the mainWindow
      menuFile->addAction("Quitter", this, SLOT(close()) );

    /* ---- */


    refreshData();


    /* TODO réimpliément QDropEvent
    fonction */
    //QDropEvent *myQdropEvent = new QDropEvent();

    /* TODO réimpliément QDragEvent */

    //ui->listView->flow(QListView::LeftToRight);

    //QLabel  *label_img  = new QLabel(this);
    //QPixmap *pixmap_img = new QPixmap("/home/mtparet3/QtSDK/test3/images/1.jpg");
    //label_img->setPixmap(*pixmap_img);
    //ui->gridLayout->addWidget(label_img);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshData(){
    chargeListSequenceInSelector(myMem.listSequence);


    QWidget *viewport = new QWidget;
    viewport->setLayout(ui->verticalLayout);

    ui->scrollArea->setWidget(viewport);

    if(!myMem.listSequence.isEmpty()){
        selectSeq = myMem.listSequence.first();
        ui->listWidget_2->chargeListImageInsequence(selectSeq, false);
    }


}

void MainWindow::chargeListSequenceInSelector(QList<Sequence> listSeq){

    ui->verticalLayout = new QVBoxLayout (ui->centralWidget);
    Sequence seq;
    foreach(seq,listSeq){
        widgetInSelector *mylistSelector = new widgetInSelector(ui->centralWidget,&seq);
        ui->verticalLayout->addWidget(mylistSelector);
    }
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
    //connect(newSequence, SIGNAL(updateUi()), this, SLOT(updateUi()));
    newSequence->show();
}

void MainWindow::updateUi(){
    this->refreshData();
}

