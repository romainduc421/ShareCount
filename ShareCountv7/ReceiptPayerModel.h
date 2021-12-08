#ifndef RECEIPTPAYERMODEL_H
#define RECEIPTPAYERMODEL_H

#include <QAbstractItemModel>
#include "Person.h"
#include "Group.h"
#include "Recepisse.h"

class ReceiptPayerModel : public QAbstractItemModel
{
    Q_OBJECT
private:
    Group *m_pGroup;
    Recepisse *m_pReceipt;
public:
    ReceiptPayerModel();

    ReceiptPayerModel(Group*, Recepisse*, QObject *parent = 0);

    virtual QModelIndex	index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    void AddPayer( Person::IDType id, Amount a );
    void RemovePayer( const QModelIndex& index );
    virtual QModelIndex	parent(const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual ~ReceiptPayerModel();
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
protected:

    QVariant GetPayerAmount(const QModelIndex &index) const;
    QVariant GetPayerName(const QModelIndex &index) const;
    QVariant GetData(const QModelIndex &index) const;


};

#endif // RECEIPTPAYERMODEL_H included
