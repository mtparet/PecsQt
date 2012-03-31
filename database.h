#ifndef DATABASE_H
#define DATABASE_H
#include <QString>
#include <QObject>
#include <QHash>
#include "model.h"

const QString database_type = "QSQLITE";
const QString database_name = "memory.db";

class Database
{
public:
    bool exec(QString &query);

    bool initialise();
    QList<QList<QString> > exec_list(QString &query);
    QList<QList<QString> > exec_list(const char* querychar);
    QList<QList<QString> > get(QList<QString> &listRow,QString &nameTable);
    bool insert(QHash<QString,QString> &listValues,QString &nameTable);
    bool insert(Model &model);
    bool addModel(QObject model);


protected:
    QList<QObject> listModel;



};

#endif // DATABASE_H
