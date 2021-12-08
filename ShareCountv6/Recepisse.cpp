#include "Recepisse.h"
#include "algorithm"
#include <QLocale>
#include <numeric>

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

Amount operator+(const Amount& a1, Recepisse::AmountMap::const_iterator payer)
{
    return a1 + payer->second;
}

Amount StripID(const std::pair<Person::IDType, Amount> p)
{
    return std::get<1>(p);
}

const Amount Recepisse::GetTotalAmount() const
{
    std::vector<Amount> amounts;
    std::transform( m_Payers.cbegin(), m_Payers.cend(), std::back_inserter(amounts), StripID);
    return std::accumulate( amounts.begin(), amounts.end(), Amount(0));
}

void Recepisse::SetDate(const boost::gregorian::date &d)
{
    m_Date = d;
}

boost::gregorian::date	Recepisse::GetDate() const
{
    return m_Date;
}



void Recepisse::SetPayeeID(const int PayeeID)
{
    m_PayeeID = PayeeID;
}

const Payee::IDType	Recepisse::GetPayeeID() const
{
    return m_PayeeID;
}

QString		Recepisse::GetDescription() const
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
