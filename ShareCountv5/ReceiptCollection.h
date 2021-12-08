#ifndef RECEIPTCOLLECTION_H
#define RECEIPTCOLLECTION_H

#include <boost/serialization/vector.hpp>
#include "QString"
#include "QStringSerialize.h"
#include <vector>

#include "Recepisse.h"


class ReceiptCollection
{
private:
    std::vector<Recepisse>      m_Receipts;
    QString                     m_Name;
public:
    ReceiptCollection();
    ReceiptCollection(QString name);

    void SetName(QString name);
    QString GetName() const;

    void AddReceipt(const Recepisse &r);
    Recepisse& GetReceipt(int);
    const Recepisse& GetReceipt(int) const;
    int NumberOfReceipts() const;

    std::vector<Recepisse>::const_iterator cbegin() const;
    std::vector<Recepisse>::const_iterator cend() const;

    bool operator==(const ReceiptCollection& other) const;

    template <class Archive>
    void serialize(Archive &ar, const unsigned int version = 0)
    {
        ar & m_Receipts;
        ar & m_Name;
    }
};

#endif // RECEIPTCOLLECTION_H included
