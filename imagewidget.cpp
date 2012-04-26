#include "imagewidget.h"
#include "imageinsequence.h"
#include "util.h"
#include "ui_imagewidget.h"
#include <QDragEnterEvent>

ImageWIdget::ImageWIdget(QWidget *parent, ImageInSequence *imS, int placeE, QString *folder) :
    QWidget(parent),
    ui(new Ui::ImageWIdget)
{
    this->setAccessibleName(imS->img.image_file);
    myS = new ImageInSequence(imS);
    place = placeE;
    myFolder = *folder;

    ui->setupUi(this);
    QPixmap qp = Util::getPixmapFile(myS.img.image_file,myFolder);
    ui->label->setPixmap(qp);
    setAcceptDrops(true);

}

void ImageWIdget::mouseMoveEvent(QMouseEvent *event)
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

void ImageWIdget::makeDrag()
{
    QDrag *dr = new QDrag(this);
    // The data to be transferred by the drag and drop operation is contained in a QMimeData object
    QMimeData *data = new QMimeData;
    data->setText(myS.img.image_file);

    // Assign ownership of the QMimeData object to the QDrag object.
    dr->setMimeData(data);
    // Start the drag and drop operation
    Qt::DropAction dropAction = dr->exec(Qt::MoveAction);

}

void ImageWIdget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        dragStartPosition = event->pos();
}

void ImageWIdget::dragMoveEvent(QDragMoveEvent *de)
{
    // The event needs to be accepted here
    de->accept();
}

void ImageWIdget::dragEnterEvent(QDragEnterEvent *event)
{
    // Set the drop action to be the proposed action.
    event->acceptProposedAction();
}

void ImageWIdget::dropEvent(QDropEvent *de)
{
}

void ImageWIdget::changeImage(bool present){
    if(present){
        QPixmap qp = Util::getPixmapFile(this->myS.img.image_file,myFolder);
        ui->label->setPixmap(qp);
    }else{
        QPixmap qp;
        ui->label->setPixmap(qp);
    }
}

ImageWIdget::~ImageWIdget()
{
    delete ui;
}
