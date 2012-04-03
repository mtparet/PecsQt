#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsequence.h"
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

      // Add an item "Bye" connected to the slot  "close" of the mainWindow
      menuFile->addAction("Quitter", this, SLOT(close()) );

    /* ---- */

    QString name = "/home/mtparet3/QtSDK/test3/images/1.jpg";
    QString name1 = "/home/mtparet3/QtSDK/test3/images/2.jpg";
    QString name2 = "/home/mtparet3/QtSDK/test3/images/3.jpg";

    ui->listWidget_2->addImage(name2,QIcon(name2),1);
    ui->listWidget_2->addImage(name1,QIcon(name1),1);
    ui->listWidget_2->addImage(name,QIcon(name),1);


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

void MainWindow::open_newsequence()
{
    NewSequence *newSequence = new NewSequence(this);
    newSequence->show();
}

