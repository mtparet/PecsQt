#ifndef MODEL_H
#define MODEL_H

#include <QHash>

class Model
{
public:
    Model();
    bool save();
    bool remove();
    template <typename Type> QList<Type> all();

protected:
    QHash<QString,QString> listRow;
    QHash<QString,QString> listValues;
    QString table;

};

#endif // MODEL_H
