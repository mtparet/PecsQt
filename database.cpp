#include "database.h"
#include "model.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include <QSqlRecord>

bool Database::addModel(QObject model){
}

bool Database::initialise(){
    QSqlDatabase db = QSqlDatabase::addDatabase(database_type);
    db.setDatabaseName(database_name);
    bool test = db.open();

    QString query = "SELECT * FROM sqlite_master WHERE type='table'";
    QSqlQuery *sq = new QSqlQuery(db);
    test = sq->exec(query);
    QString value;
    QSqlRecord rec = sq->record();
    int i = 0; // ligne
        while (sq->next()) // parcours de chaque lignes du résultat
        {
            int j = 0; // colonne
            while (j < rec.count())
            {
                value = sq->value(j).toString();
                j++;
            }
            i++;
        }
    db.close();
}

QList<QList<QString> > Database::exec_list(QString &query){
    QSqlDatabase db = QSqlDatabase::addDatabase(database_type);
    db.setDatabaseName(database_name);
    bool test = db.open();
    QSqlQuery sq = db.exec(query);
    QSqlRecord rec = sq.record();
    QList<QList<QString> > *ListResult = new QList<QList<QString> >();

    int k = 0; // colonne
    while (k < rec.count())
    {
        QList<QString> *result = new QList<QString>();
        ListResult->insert(k,*result);
        k++;
    }


    int i = 0; // ligne
        while (sq.next()) // parcours de chaque lignes du résultat
        {
            int j = 0; // colonne
            while (j < rec.count())
            {
                QList<QString> oneList = ListResult->at(j);
                oneList.insert(i,sq.value(j).toString());
                ListResult->replace(j,oneList);
                //ListResult->valueinsert(i,sq->value(j).toString());
                j++;
            }
            i++;
        }

    db.close();
    return *ListResult;
}

QList<QList<QString> > Database::get(QList<QString> &listRow,QString &nameTable){

    int i = 0;
    for( i = 0; i < listRow.count(); i++){
        if(i == 0){
            listRow[i] = " " + listRow[i];
        }else{
            listRow[i] = " ," + listRow[i];
        }
    }

    QString stringRow;
    QString str;
    foreach(str,listRow){
        stringRow = " " + str;
    }

    QString query = "SELECT" + stringRow + " FROM " + nameTable;
    return exec_list(query);
}

bool Database::insert(QHash<QString, QString> &listValues,QString &nameTable){


    QList<QString> itKey = listValues.keys();

    QString stringValues;
    QString stringRow;
    int i = 0;
    for( i = 0; i < itKey.count(); i++){
        QString stringValuesTemp = "";
        QString stringRowTemp = "";

        if(i == 0){
            stringValuesTemp = "'" + listValues.value(itKey.at(i)) + "'";
            stringRowTemp = itKey.at(i);
        }else{
            stringValuesTemp = " ,'" + listValues.value(itKey.at(i)) + "'";
            stringRowTemp = " ," + itKey.at(i);
        }

        stringValues = stringValues + stringValuesTemp;
        stringRow = stringRow + stringRowTemp;

    }

    QString query = "INSERT INTO " + nameTable + " (" + stringRow + ") VALUES (" + stringValues + ");" ;
    return exec(query);
}



QList<QList<QString> > Database::exec_list(const char* querychar){
    QString *query = new QString(querychar);
    exec_list(*query);
}

bool Database::exec(QString &query){
    QSqlDatabase db = QSqlDatabase::addDatabase(database_type);
    db.setDatabaseName(database_name);
    bool test = db.open();
    db.exec(query);
    QSqlError error = db.lastError();
    db.close();
    return test;
}

