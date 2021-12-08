#include "Recepisse.h"

Recepisse::Recepisse() :
    m_Amount(0)
{

}

void Recepisse::SetTotalAmount(const Amount a)
{
    m_Amount = a;
}

void Recepisse::AddPayerByAmount(const Person::IDType id, const Amount a)
{
    m_Payers.insert( std::pair<Person::IDType,Amount>(id, a) );
}

void Recepisse::AddDebtorByAmount(const Person::IDType id, const Amount a)
{
    m_Debtors.insert( std::pair<Person::IDType,Amount>(id, a) );
}

void Recepisse::RemovePayer(const Person::IDType id)
{
    m_Payers.erase( id );
}

void Recepisse::RemoveDebtor(const Person::IDType id)
{
    m_Debtors.erase( id );
}

const Recepisse::AmountMap&	Recepisse::GetPayers() const
{
    return m_Payers;
}

const Recepisse::AmountMap&	Recepisse::GetDebtors() const
{
    return m_Debtors;
}



void Recepisse::SetPayeeID(const int PayeeID)
{
    m_PayeeID = PayeeID;
}

const Payee::IDType	Recepisse::GetPayeeID() const
{
    return m_PayeeID;
}

QString const&		Recepisse::GetDescription() const
{
    return m_Desc;
}

void Recepisse::SetDescription(QString const& desc)
{
    m_Desc = desc;
}

void Recepisse::SetCategory(const int CategoryID)
{
    m_Category = CategoryID;
}
