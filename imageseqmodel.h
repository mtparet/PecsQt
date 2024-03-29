#ifndef IMAGESEQMODEL_H
#define IMAGESEQMODEL_H
#include "imageinsequence.h"
#include "QAbstractListModel"
#include "sequence.h"
class ImageSeqModel: public QAbstractListModel
{   
    Q_OBJECT
public:
    explicit ImageSeqModel(QObject *parent=0,Sequence *seq = 0,bool display_cadre = true);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::DropActions supportedDropActions() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    QStringList mimeTypes() const;
    QMimeData * mimeData ( const QModelIndexList & indexes ) const;
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    bool removeRows(int row, int count, const QModelIndex &parent);
    Qt::DropActions supportedDragActions() const;

protected:
    Sequence seq;
    bool display_cadre;
signals:

public slots:
};

#endif // IMAGESEQMODEL_H
