#include "Group.h"

#include <iostream>
#include <boost/function.hpp>
#include <algorithm>
#include <boost/bind.hpp>
#include <QLocale>

Group::Group()
{

}



bool NameIsNot(QString name, const Person &p)
{
    return !( p.getName() == name );
}

void Group::addGroupMember(Person *p)
{
    if (std::all_of(m_groupMembers.begin(), m_groupMembers.end(),
        boost::bind( NameIsNot, p->getName(), _1 ) ) )
    {
        p->SetID(nextMemberID());
        m_groupMembers.push_back( p );
    } else {
        throw std::runtime_error("Someone else with that name already exists in the group, so no group member will be added.");
    }
}

void Group::removeGroupMember(Person::IDType ID)
{
    if(memberCanBeRemoved(ID))
    {
        m_groupMembers.erase( std::remove( std::begin(m_groupMembers), std::end(m_groupMembers), ID),
        std::end(m_groupMembers) );
    }
    else
    {
        throw std::runtime_error
        ("Member cannot be removed because receipts have already been added which reference this user.");
    }

}


size_t Group::size() const
{
    return m_groupMembers.size();
}

Person& Group::member(size_t i)
{
    return m_groupMembers[i];
}


bool MemberIsNotOnReceipt(Person::IDType ID, const Recepisse& R )
{
    return ( R.GetPayers().count(ID) == 0 &&
        R.GetDebtors().count(ID) == 0 );
}

bool PayeeIsNotOnReceipt(Person::IDType ID, const Recepisse& R )
{
    return (R.GetPayeeID() != ID);
}

void Group::addGroupPayee(Payee *p)
{
    p->SetID(nextPayeeID());
    m_Payees.push_back( p );
}

bool NoReferencesInCollection(Person::IDType ID, const ReceiptCollection& rc)
{
    boost::function<bool (const Recepisse&)> MemberIsNotOnReceiptFn =
        boost::bind( MemberIsNotOnReceipt, ID, _1);
    return std::all_of( rc.cbegin(), rc.cend(), MemberIsNotOnReceiptFn );
}

bool Group::memberCanBeRemoved(Person::IDType ID) const
{
    boost::function<bool (const ReceiptCollection&)> MemberHasNoReferences =
        boost::bind(static_cast<bool (*)(Person::IDType, ReceiptCollection const&) >(NoReferencesInCollection)
                , ID, _1);
    bool result = std::all_of( m_Collections.cbegin(), m_Collections.cend(), MemberHasNoReferences);
    if (result == true)
    {
        std::cout << "member can be removed" << std::endl;
    }
    else
    {
        std::cout << "member cannot be removed" << std::endl;
    }
    return result;
}


bool NoReferencesInCollection(Payee::IDType ID, const ReceiptCollection& rc)
{
    boost::function<bool (const Recepisse&)> PayeeIsNotOnReceiptFn =
        boost::bind( PayeeIsNotOnReceipt,
                     ID, _1);
    return std::all_of( rc.cbegin(), rc.cend(), PayeeIsNotOnReceiptFn );
}

Person::IDType Group::nextMemberID() const
{
    boost::ptr_vector<Person>::const_iterator iter = std::max_element( m_groupMembers.begin(), m_groupMembers.end() );
    if (iter != m_groupMembers.end())
    {
        return Person::IDType( iter->getID() + 1 );
    }
    else{
        return 0;
    }
}

Payee::IDType Group::nextPayeeID() const
{
    boost::ptr_vector<Payee>::const_iterator iter = std::max_element( m_Payees.begin(), m_Payees.end() );
    if (iter != m_groupMembers.end())
    {
        return Payee::IDType( iter->GetID() + 1 );
    }
    else{
        return 0;
    }
}

bool Group::payeeCanBeRemoved(Payee::IDType ID) const
{
    boost::function<bool (const ReceiptCollection&)> payeeHasNoReferences =
        boost::bind( static_cast< bool (*)(Payee::IDType, ReceiptCollection const&) >(NoReferencesInCollection),
                     ID, _1);
    bool result = std::all_of( m_Collections.cbegin(), m_Collections.cend(), payeeHasNoReferences);
    if (result == true)
        std::cout << "payee can be removed" << std::endl;
    else
        std::cout << "payee cannot be removed" << std::endl;
    return result;
}



bool MemberIDMatch(Person::IDType id, const Person& p)
{
    return (p.getID() == id);
}


const Person&   Group::GetMemberByID(Person::IDType id) const
{
    boost::ptr_vector<Person>::const_iterator  iter = std::find_if( m_groupMembers.begin(), m_groupMembers.end(),
                                                                 boost::bind(MemberIDMatch, id, _1) );
    if (iter == m_groupMembers.end())
    {
        throw std::runtime_error("Could not find person with given id.");
    }
    else{
        return *iter;
    }
}

Person&   Group::GetMemberByID(Person::IDType id)
{
    boost::ptr_vector<Person>::iterator  iter = std::find_if( m_groupMembers.begin(), m_groupMembers.end(),
                                                                 boost::bind(MemberIDMatch, id, _1) );
    if (iter == m_groupMembers.end())
    {
        throw std::runtime_error("Could not find person with given id.");
    }
    else{
        return *iter;
    }
}




int Group::GetNumberOfReceiptCollections() const
{
    return m_Collections.size();
}

const ReceiptCollection&	Group::GetReceiptCollection(int i) const
{
    return m_Collections.at(i);
}

ReceiptCollection&	Group::GetReceiptCollection(int i)
{
    return m_Collections.at(i);
}

QString	Group::formatReceiptDescription(Recepisse const& r)
{
    QLocale locale;
    return locale.toCurrencyString( r.GetTotalAmount().convert_to<double>() );
}

bool CollectionNameEquals(const ReceiptCollection& rc, QString const& name)
{
    return (rc.GetName() == name);
}

void Group::AddReceiptCollection(QString const& name)
{
    if ( std::any_of(m_Collections.begin(), m_Collections.end(),
                    boost::bind(CollectionNameEquals, _1, name)) )
        throw std::runtime_error("Can't add receipt collection with a name that's already been used for a previous receipt collection");
    else {
        m_Collections.push_back( new ReceiptCollection(name) );
    }
}
