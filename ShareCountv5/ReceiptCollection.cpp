#include "ReceiptCollection.h"

ReceiptCollection::ReceiptCollection()
{
}

ReceiptCollection::ReceiptCollection(QString name) :
m_Name(name)
{
}

void ReceiptCollection::SetName(QString name)
{
    m_Name = name;
}

QString ReceiptCollection::GetName() const
{
    return m_Name;
}

void ReceiptCollection::AddReceipt(const Recepisse &r)
{
    m_Receipts.push_back(r);
}

std::vector<Recepisse>::const_iterator ReceiptCollection::cbegin() const
{
    return m_Receipts.cbegin();
}

std::vector<Recepisse>::const_iterator ReceiptCollection::cend() const
{
    return m_Receipts.cend();
}

int ReceiptCollection::NumberOfReceipts() const
{
    return m_Receipts.size();
}

Recepisse& ReceiptCollection::GetReceipt(int i)
{
    return m_Receipts.at(i);
}

const Recepisse& ReceiptCollection::GetReceipt(int i) const
{
    return m_Receipts.at(i);
}

bool ReceiptCollection::operator==(const ReceiptCollection& other) const
{
    return (this->GetName() == other.GetName());
}
