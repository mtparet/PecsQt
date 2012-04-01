#include <QtGui/QApplication>
#include "database.h"
#include "mainwindow.h"
#include "images.h"
#include "sequence.h"
#include "imageinsequence.h"
#include <QDebug>
#include <QMetaObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName( "pecs.db" );

    db.open();
    // Hold a connection to a database. It is needed before any database access using DQModel.
    DQConnection connection;

    connection.open(db); // Establish the connection to database. It will become the "default connection" shared by all DQModel

    connection.addModel<Images>(); // Register a model to the connection
    connection.addModel<ImageInSequence>(); // Register a model to the connection
    connection.addModel<Sequence>();

    connection.createTables(); // Create table for all added model


    //Images.metaObject()->
    Images image;
    image.image_file = "testaz";
    image.name ="ici";

    qDebug() << image.save();
    qDebug() << image.id;

    ImageInSequence is;
    is.orderIn = 0;
    qDebug() << "loaded";
    qDebug() << is.a.isLoaded();
    is.a = image;
     qDebug() << is.a.isLoaded();
    qDebug() << is.save();

    Sequence sq;
    sq.name = "sequence1";
    sq.addImageInSequence(is);
    qDebug() << sq.save();
    sq.getListImageInSequence();


    DQList<ImageInSequence> list = ImageInSequence::objects().all();

       qDebug() << list;

       int n = list.size();
       qDebug() << "The friend of tester1: ";
       for (int i = 0 ; i < n;i++) {
           ImageInSequence* f = list.at(i);

           qDebug() << f->a->image_file;
           /*
             f->b is a DQForeignKey field. DQForeignKey support -> operation overloading
             and you can access the field of the foreign  table. In this case,
             it is User. So f->b->userId is the equivalent to user.userId.

               FriendShip::objects().filter(DQWhere("a = ", tester1.id )).all()

             Morever, the query above will not access the "user" table. DQForeignKey will
             load the foreign table's record on request automatically.
            */
       }

    MainWindow w;
    w.show();

    
    return a.exec();
}
