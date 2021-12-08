#include "Person.h"

static unsigned int nextID = 0;

Person::Person() //:
    /*m_ID( nextID++ )*/
{
}

Person::Person(const QString& str) :
    m_name (str)/*,
    m_ID( nextID++ )*/
{

}

Person::Person(const Person& other) :
    m_name (other.m_name)/*,
    m_ID (other.m_ID)*/
{

}

bool Person::operator==(Person const& other)
{
    return (this->m_ID == other.m_ID);
}

bool Person::operator==(Person::IDType id)
{
    return (this->m_ID == id);
}

void Person::SetName(QString const& name)
{
    m_name = name;
}

void Person::SetID(Person::IDType id)
{
    m_ID = id;
}

/*bool operator<(const Person& p1, const Person& p2)
{
    return (p1.getID() < p2.getID());
}*/

/*bool Person::operator <(const Person other) const{

    return (*this).getID() < other.getID();
}
*/

bool operator<(const Person& p1, const Person& p2)
{
    return (p1.getID() < p2.getID());
}
