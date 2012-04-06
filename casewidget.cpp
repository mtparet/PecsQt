#include "casewidget.h"
#include "ui_casewidget.h"
#include "imageinsequence.h"
#include "util.h"

CaseWidget::CaseWidget(QWidget *parent, ImageInSequence *imS, int placeE, QString *folder) :
    QWidget(parent),
    ui(new Ui::CaseWidget)
{
    myS = new ImageInSequence(imS);
    place = placeE;
    QString myFolder = *folder;

    ui->setupUi(this);
    //QGraphicsPixmapItem item(Util::getPixmapFile(myS.img.image_file,myFolder));
    QPixmap qp = Util::getPixmapFile(myS.img.image_file,myFolder);
    QGraphicsScene scene;
    scene.addPixmap(qp);
    ui->graphicsView_2->setScene(&scene);

    //ui->graphicsView_2->setAcceptDrops(true);
    //ui->graphicsView_2->setDragMode(QGraphicsView::ScrollHandDrag);
    //ui->graphicsView_2->setDragMode();
}

CaseWidget::~CaseWidget()
{
    delete ui;
}
