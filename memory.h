#ifndef MEMORY_H
#define MEMORY_H
#include <QList>
#include <sequence.h>

class Memory
{
public:
    QList<Sequence *> listSequence;
    QSize *size_in_widget;
    QSize *size_in_view;
    bool replace(Sequence f);
    bool remove(Sequence f);
    bool add(Sequence f);


};

#endif // MEMORY_H
