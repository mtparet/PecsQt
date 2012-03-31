#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon *icon = new QIcon("/home/mtparet3/QtSDK/test3/images/1.jpg");
    QIcon *icon1 = new QIcon("/home/mtparet3/QtSDK/test3/images/2.jpg");
    QIcon *icon2 = new QIcon("/home/mtparet3/QtSDK/test3/images/3.jpg");
    QListWidgetItem *a = new QListWidgetItem("aa");
    a->setIcon(*icon);
    ui->listWidget_2->addItem(a);

    QListWidgetItem *c = new QListWidgetItem("aa");
    c->setIcon(*icon1);
    ui->listWidget_2->addItem(c);

    QListWidgetItem *b = new QListWidgetItem("aa");
    b->setIcon(*icon2);
    ui->listWidget_2->addItem(b);

    QSize *image_size = new QSize(100,100);


    ui->listWidget_2->setIconSize(*image_size);
    ui->listWidget_2->setMaximumHeight(image_size->height()+10);
    ui->listWidget_2->setGridSize(*image_size);

    ui->listWidget->setMaximumHeight(image_size->height()+10);
    ui->listWidget->setIconSize(*image_size);
    ui->listWidget->setGridSize(*image_size);

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
