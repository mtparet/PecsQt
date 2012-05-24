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
    chargeListSequenceInSelector(myMem.listSequence);


    QWidget *viewport = new QWidget;
    viewport->setLayout(ui->verticalLayout);

    ui->scrollArea->setWidget(viewport);

    if(!myMem.listSequence.isEmpty()){
        Sequence *sq = myMem.listSequence.first();
        selectOneSequence(sq);
    }


}

void MainWindow::selectOneSequence(Sequence *seq){
    selectSeq = seq;

    initLayoutSequence();

    for(int i = 0; i < selectSeq.listImageInSequence.length(); i++){
        sequenceInReceptor.append("null");
    }

    buildLayoutReceptor();

}

void MainWindow::chargeListSequenceInSelector(QList<Sequence*> listSeq){

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

    buildLayoutReceptor();
    updateLayoutSequence(name,present);
}

void MainWindow::buildLayoutReceptor(){

    ImageSeqModel *seqModel = new ImageSeqModel(this,&selectSeq.listImageInSequence);
    ImageReceptorDelegate * seqDelegate = new ImageReceptorDelegate(this);
        ui->listView->setItemDelegate(seqDelegate);
        ui->listView->setModel(seqModel);

        ui->listView->setDragEnabled(true);
        ui->listView->setAcceptDrops(true);
        ui->listView->setDropIndicatorShown(true);

}

void MainWindow::updateLayoutSequence(QString name, bool present){


    ImageInSequence imgS = this->selectSeq.getImageInsequence(name);
    this->selectSeq.setImageInsequence(imgS);


    if ( ui->horizontalLayout_8 != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->horizontalLayout_8->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
    }

    initLayoutSequence();

}

void MainWindow::initLayoutSequence(){

    ImageInSequence imS;
    int i = 0;
    foreach(imS,selectSeq.listImageInSequence){
        ImageWIdget *myWidgetReceptor = new ImageWIdget(ui->centralWidget,&imS,i,&selectSeq.name);
        myWidgetReceptor->setAcceptDrops(true);
        connect(myWidgetReceptor, SIGNAL(updateLayoutSequence(QString,bool)), this, SLOT(updateLayoutSequence(QString,bool)));

        listImageWidget.append(myWidgetReceptor);

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

