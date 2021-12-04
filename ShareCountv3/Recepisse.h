#ifndef RECEPISSE_H
#define RECEPISSE_H

#include <map>
#include "Person.h"
#include "ConvertToAmount.h"
#include <boost/serialization/map.hpp>
#include <boost/date_time/gregorian/greg_serialize.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/date_time/gregorian/greg_date.hpp>

class Recepisse
{
private:
    Amount	m_Amount;
    std::map<Person::IDType, Amount> m_Payers;
    std::map<Person::IDType, Amount> m_Debtors;

    int			m_MerchantID;
    QString		m_Desc;
    int			m_Category;

public:
    typedef std::map<Person::IDType,Amount>     AmountMap;
    Recepisse();

    /*!
     * \brief SetTotalAmount
     */
    void SetTotalAmount(const Amount);

    /*!
     * \brief AddPayerByAmount
     */
    void AddPayerByAmount(const Person::IDType, const Amount);

    /*!
     * \brief AddDebtorByAmount
     */
    void AddDebtorByAmount(const Person::IDType, const Amount);

    /*!
     * \brief RemovePayer
     */
    void RemovePayer(const Person::IDType);

    /*!
     * \brief RemoveDebtor
     */
    void RemoveDebtor(const Person::IDType);

    /*!
     * \brief GetPayers
     * \return
     */
    const AmountMap&	GetPayers() const;

    /*!
     * \brief GetDebtors
     * \return
     */
    const AmountMap&	GetDebtors() const;

    template<class Archive>
    /*!
     * \brief serialize
     * \param ar
     * \param version
     */
    void serialize(Archive &ar, int version = 0)
    {
        ar & m_Amount;
        ar & m_Payers;
        //ar & m_Allocation;
        ar & m_MerchantID;
        ar & m_Desc;
        ar & m_Category;
    }
};

#endif
/* RECEPISSE_H included */
