#ifndef IMAGESEQMODEL_H
#define IMAGESEQMODEL_H
#include "imageinsequence.h"
#include "QAbstractListModel"
class ImageSeqModel: public QAbstractListModel
{   
    Q_OBJECT
public:
    explicit ImageSeqModel(QObject *parent=0,QList<ImageInSequence> *li = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::DropActions supportedDropActions() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    QStringList mimeTypes() const;
    QMimeData * mimeData ( const QModelIndexList & indexes ) const;
    bool insertRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
    bool insertColumns ( int column, int count, const QModelIndex & parent = QModelIndex() );
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    bool setItemData ( const QModelIndex & index, const QMap<int, QVariant> & roles );
protected:
    QList<ImageInSequence> li;
signals:

public slots:
};

#endif // IMAGESEQMODEL_H
