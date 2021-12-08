#ifndef RECEIPTCOLLECTIONMODEL_H
#define RECEIPTCOLLECTIONMODEL_H

#include "Group.h"
#include <QAbstractItemModel>

class ReceiptCollectionModel : public QAbstractItemModel
{
    Q_OBJECT
private :
    Group* m_pGroup;
public:
    ReceiptCollectionModel( Group *g, QObject *parent = 0 );
    virtual QModelIndex	index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex	parent(const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // RECEIPTCOLLECTIONMODEL_H
