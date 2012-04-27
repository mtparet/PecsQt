#include "casewidget.h"
#include "ui_casewidget.h"
#include "imageinsequence.h"
#include "util.h"
#include <QDragEnterEvent>

CaseWidget::CaseWidget(QWidget *parent, ImageInSequence *imS, int placeE, QString *folder) :
    QWidget(parent),
    ui(new Ui::CaseWidget)
{
    myS = new ImageInSequence(imS);
    place = placeE;
    QString myFolder = *folder;

    ui->setupUi(this);
    if(imS->img.name == "null"){
        myFolder = "null";
    }

    QPixmap qp = Util::getPixmapFile(myS.img.image_file,myFolder);
    ui->label->setPixmap(qp);
    setAcceptDrops(true);

}

void CaseWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton))
        return;
    if ((event->pos() - dragStartPosition).manhattanLength()
         < QApplication::startDragDistance())
        return;

    makeDrag();


    //Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction);
    //...
}

void CaseWidget::makeDrag()
{
    QDrag *dr = new QDrag(this);
    // The data to be transferred by the drag and drop operation is contained in a QMimeData object
    QMimeData *data = new QMimeData;
    data->setText(myS.img.image_file);

    // Assign ownership of the QMimeData object to the QDrag object.
    dr->setMimeData(data);
    // Start the drag and drop operation
    dr->start();
}

void CaseWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        dragStartPosition = event->pos();
}

void CaseWidget::dragMoveEvent(QDragMoveEvent *de)
{
    // The event needs to be accepted here
    de->accept();
}

void CaseWidget::dragEnterEvent(QDragEnterEvent *event)
{
    // Set the drop action to be the proposed action.
    event->acceptProposedAction();
}

void CaseWidget::dropEvent(QDropEvent *de)
{
    de->accept();
    QString name = de->mimeData()->text();
    this->updateReceptor(name,this->place,name,false);
    //this->updateLayoutSequence("name",false);
}

CaseWidget::~CaseWidget()
{
    delete ui;
}
