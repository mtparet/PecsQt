#include "imageseqmodel.h"
#include "imageinsequence.h"
#include "QMimeData"
#include "QStringList"

ImageSeqModel::ImageSeqModel(QObject *parent, QList<ImageInSequence> *li) :
    QAbstractListModel(parent)
{
    this->li = *li;
    reset();
}

int ImageSeqModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return li.count();
}

QVariant ImageSeqModel::data(const QModelIndex &index, int role) const {
     int row = index.row();

     if (role != Qt::DisplayRole){
         return (QVariant::Invalid);
    }
    if ((index.column() == 0) && (row >= 0) && (row < rowCount()))
    {
      ImageInSequence is = li.at(index.row());
      return is.toVariantMap();
    }
    return (QVariant::Invalid);
}



Qt::DropActions ImageSeqModel::supportedDropActions() const
 {
     return Qt::CopyAction | Qt::MoveAction;
 }

 Qt::ItemFlags ImageSeqModel::flags(const QModelIndex &index) const{
     Qt::ItemFlags defaultFlags = 0;

     if (index.isValid())
         return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags;
     else
         return Qt::ItemIsDropEnabled | defaultFlags;

 }

 bool ImageSeqModel::dropMimeData(const QMimeData *data,
     Qt::DropAction action, int row, int column, const QModelIndex &parent)
 {
     if (action == Qt::IgnoreAction)
         return true;

     if (column > 0)
         return false;

     int beginRow;

      if (row != -1)
          beginRow = row;
      else if (parent.isValid())
               beginRow = parent.row();
      else
          beginRow = rowCount(QModelIndex());

 }

QStringList ImageSeqModel::mimeTypes() const{
    QStringList s;
    return s;
}

QMimeData * ImageSeqModel::mimeData ( const QModelIndexList & indexes ) const{
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("bonjour");
    return mimeData;
}

bool ImageSeqModel::insertRows ( int row, int count, const QModelIndex & parent  ){

}

bool ImageSeqModel::insertColumns ( int column, int count, const QModelIndex & parent ){

}

bool ImageSeqModel::setData ( const QModelIndex & index, const QVariant & value, int role  ){

}

bool ImageSeqModel::setItemData ( const QModelIndex & index, const QMap<int, QVariant> & roles ){

}
