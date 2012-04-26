#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newsequence.h"
#include "mylistwidget.h"
#include "sequence.h"
#include "widgetinselector.h"
#include "globval.h"
#include "util.h"
#include "organizedialog.h"
#include "casewidget.h"
#include "apiparse.h"
#include "importdialog.h"
#include "imagewidget.h"
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
    chargeListSequenceInSelector(myMem.listSequence);


    QWidget *viewport = new QWidget;
    viewport->setLayout(ui->verticalLayout);

    ui->scrollArea->setWidget(viewport);

    if(!myMem.listSequence.isEmpty()){
        selectSeq = myMem.listSequence.first();
        initLayoutSequence(myMem.listSequence.first());

        for(int i; i < selectSeq.listImageInSequence.length(); i++){
            sequenceInReceptor.append("null");
        }

        buildLayoutReceptor();
    }


}

void MainWindow::chargeListSequenceInSelector(QList<Sequence> listSeq){

    ui->verticalLayout = new QVBoxLayout (ui->centralWidget);
    Sequence seq;
    foreach(seq,listSeq){
        widgetInSelector *mylistSelector = new widgetInSelector(ui->centralWidget,&seq);
        mylistSelector->setMinimumWidth(100);
        ui->verticalLayout->addWidget(mylistSelector);
    }
}

void MainWindow::updateReceptor(QString id_name,int num_place,QString name,bool present){
    this->sequenceInReceptor = Util::insert_at(id_name,num_place,this->sequenceInReceptor);

    if ( ui->horizontalLayout_2 != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->horizontalLayout_2->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }

    buildLayoutReceptor();
    updateLayoutSequence(name,present);
}

void MainWindow::buildLayoutReceptor(){

    QString name;
    int i = 0;
    foreach(name,this->sequenceInReceptor){
        ImageInSequence imS = this->selectSeq.getImageInsequence(name);
        CaseWidget *myWidgetReceptor = new CaseWidget(ui->centralWidget,&imS,i,&selectSeq.name);
        myWidgetReceptor->setAcceptDrops(true);
        connect(myWidgetReceptor, SIGNAL(updateReceptor(QString,int,QString,bool)), this, SLOT(updateReceptor(QString,int,QString,bool)));
        connect(myWidgetReceptor, SIGNAL(updateLayoutSequence(QString,bool)), this, SLOT(updateLayoutSequence(QString,bool)));

        ui->horizontalLayout_2->addWidget(myWidgetReceptor);
        i++;
    }
}

void MainWindow::updateLayoutSequence(QString name, bool present){

    if ( ui->horizontalLayout_8 != NULL )
    {
        QLayoutItem* item;
        for(int i = 0; i< ui->horizontalLayout_8->count() ; i++){
            item = ui->horizontalLayout_8->takeAt(i);
            if(item != 0){
                ImageWIdget *ims = (ImageWIdget*) item->widget();
                if(ims->myS.img.name == name){
                    ims->changeImage(present);
                    //ui->horizontalLayout_8->in
                }
            }

        }

    }

}

void MainWindow::initLayoutSequence(Sequence sq){

    ImageInSequence imS;
    int i = 0;
    foreach(imS,sq.listImageInSequence){
        ImageWIdget *myWidgetReceptor = new ImageWIdget(ui->centralWidget,&imS,i,&sq.name);
        myWidgetReceptor->setAcceptDrops(true);
        ui->horizontalLayout_8->addWidget(myWidgetReceptor);
        i++;
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

void MainWindow::open_export()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Sélectionner le répertoire contenant les fichiers "),QString(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    Util::extractRessources(dir);
}

void MainWindow::open_import()
{
    ImportDialog *importDialog = new ImportDialog(this);
    //connect(newSequence, SIGNAL(updateUi()), this, SLOT(updateUi()));
    importDialog->show();
}

void MainWindow::updateUi(){
    this->refreshData();
}

