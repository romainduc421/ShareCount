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
