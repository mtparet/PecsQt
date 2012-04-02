#include <QtGui/QApplication>
#include "database.h"
#include "mainwindow.h"
#include "images.h"
#include "sequence.h"
#include "util.h"
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

    QMap<QString,int> listImage;
    listImage.insert("keybonjour",5);
    listImage.insert("key2",10);
    Util::createSequence(listImage,"essai");

/*
    Images image;
    image.image_file = "testaz";
    image.name ="ici";

    qDebug() << image.save();
    qDebug() << image.id;


    ImageInSequence is;
    is.orderIn = 0;

    is.a = image;
    qDebug() << is.save();


    Sequence sq;
    sq.name = "sequence1";
    sq.addImageInSequence(is);
    qDebug() << sq.save();
    //sq.getListImageInSequence();


    DQList<Sequence> list = Sequence::objects().all();

       qDebug() << list;

       int n = list.size();
       qDebug() << "The friend of tester1: ";
       for (int i = 0 ; i < n;i++) {
           Sequence* f = list.at(i);
            qDebug() << "is1" <<  "sequence" << f->is1.isLoaded();
           qDebug() << "is1" <<  "sequence" << f->is1->orderIn;
           qDebug() << "is1" <<  "sequence" << f->is1.isLoaded();
           qDebug() << "is2" <<  "sequence" << f->is2.isLoaded();
          qDebug() << "is2" <<  "sequence" << f->is2->orderIn;
          qDebug() << "is2" <<  "sequence" << f->is2.isLoaded();
          QMap<QString,int> listImage =  Util::getListImageInSequence(f);
          qDebug() << listImage;
          /*
             f->b is a DQForeignKey field. DQForeignKey support -> operation overloading
             and you can access the field of the foreign  table. In this case,
             it is User. So f->b->userId is the equivalent to user.userId.

               FriendShip::objects().filter(DQWhere("a = ", tester1.id )).all()

             Morever, the query above will not access the "user" table. DQForeignKey will
             load the foreign table's record on request automatically.

       }

       DQList<ImageInSequence> list2 = ImageInSequence::objects().all();

          qDebug() << list2;

          n = list2.size();
          qDebug() << "The friend of tester1: ";
          for (int i = 0 ; i < n;i++) {
              ImageInSequence* f = list2.at(i);

              qDebug() << "imagesequence" << f->a->image_file;
              /*
                f->b is a DQForeignKey field. DQForeignKey support -> operation overloading
                and you can access the field of the foreign  table. In this case,
                it is User. So f->b->userId is the equivalent to user.userId.

                  FriendShip::objects().filter(DQWhere("a = ", tester1.id )).all()

                Morever, the query above will not access the "user" table. DQForeignKey will
                load the foreign table's record on request automatically.

          }
*/

    MainWindow w;
    w.show();

    
    return a.exec();
}
