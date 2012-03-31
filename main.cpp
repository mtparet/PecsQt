#include <QtGui/QApplication>
#include "database.h"
#include "mainwindow.h"
#include "images.h"
#include <QDebug>
#include <QMetaObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Database *db = new Database();

    db->initialise();

    //Images.metaObject()->
    Images *image = new Images;
    image->setName("bonjour");
    image->setLocation("location");
    image->save();
    //est = image->save();

    MainWindow w;
    w.show();

    
    return a.exec();
}
