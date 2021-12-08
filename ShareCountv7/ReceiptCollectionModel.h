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
    void AddCollection(const QString& name);
    QModelIndex const&	GetCollectionIndex(QModelIndex const& index);
    void AddReceipt(const Recepisse& R, QModelIndex const& selected);
    void DeleteItem(const QModelIndex& index);
    Recepisse&			GetReceipt(QModelIndex const& index);
    ReceiptCollection&  GetReceiptCollection(QModelIndex const& index);
    void ChangeReceipt(const QModelIndex& index, Recepisse& r);

protected:
    void DeleteReceipt(const QModelIndex& index);
    void DeleteCollection(const QModelIndex& index);
};

#endif // RECEIPTCOLLECTIONMODEL_H
