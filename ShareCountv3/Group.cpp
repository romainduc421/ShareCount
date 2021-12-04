#include "Group.h"

#include <iostream>
#include <boost/function.hpp>
#include <algorithm>
#include <boost/bind.hpp>

Group::Group()
{

}

void Group::addGroupMember(Person *p)
{
    m_groupMembers.push_back( p );
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
    if (R.GetDebtors().count(ID) == 0 &&
        R.GetPayers().count(ID) == 0)
        return true;
    else
        return false;
}

bool NoReferencesInCollection(Person::IDType ID, const recepisseCollection& rc)
{
    boost::function<bool (const Recepisse&)> MemberIsNotOnReceiptFn =
        boost::bind( MemberIsNotOnReceipt, ID, _1);
    return std::all_of( rc.cbegin(), rc.cend(), MemberIsNotOnReceiptFn );
}

bool Group::memberCanBeRemoved(Person::IDType ID) const
{
    boost::function<bool (const recepisseCollection&)> MemberHasNoReferences =
        boost::bind( NoReferencesInCollection, ID, _1);
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
