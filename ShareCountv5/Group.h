#ifndef GROUP_H
#define GROUP_H
#include "Person.h"
#include "Payee.h"
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/serialize_ptr_vector.hpp>
#include "Recepisse.h"
#include <boost/ptr_container/ptr_map.hpp>
#include <vector>
#include <tuple>
#include <QString>
#include "ReceiptCollection.h"


/*!
 * \brief The Group class
 * \author
 * classe du modèle representant un groupe d'amis
 */

//typedef boost::ptr_vector<Recepisse> recepisseCollection;

class Group
{

public:

    /*!
     * \brief Group constructor
     */
    Group();

    /*!
     * \brief addGroupMember
     * \param p la personne a ajouter
     */
    void addGroupMember(Person* p);
    void addGroupPayee(Payee* p);
    /*!
     * \brief removeGroupMember
     * \param id
     */
    void removeGroupMember(Person::IDType id);

    /*!
     * \brief size
     * \return la taille du groupe
     */
    size_t size() const;

    /*!
     * \brief member
     * \return la reference d'un membre du groupe
     */
    Person& member(size_t);

    template <class Archive>
    /*!
     * \brief serialize
     * \param ar
     * \param version
     */
    void serialize(Archive& ar, const unsigned int version)
    {
        ar & m_groupMembers;
        ar & m_Collections;
        ar & m_Payees;
    }

    int GetNumberOfReceiptCollections() const;
    const ReceiptCollection&	GetReceiptCollection(int) const;
    ReceiptCollection&	GetReceiptCollection(int);
    void				AddReceiptCollection(QString const& name);

    QString	formatReceiptDescription(Recepisse const& r);


    /*!
     * \brief memberCanBeRemoved
     * \param id
     * \return
     */
    bool	memberCanBeRemoved(Person::IDType id) const;
    bool	payeeCanBeRemoved(Payee::IDType id) const;
    const Person&   GetMemberByID(Person::IDType id) const;
    Person&   GetMemberByID(Person::IDType id);

private:

    /*!
     * \brief m_groupMembers
     */
    boost::ptr_vector<Person>	m_groupMembers;

    /*!
     * \brief m_Collections
     */
    boost::ptr_vector<ReceiptCollection>  m_Collections;
    boost::ptr_vector<Payee>				m_Payees;

protected:
    Person::IDType	nextMemberID() const;
    Payee::IDType   nextPayeeID() const;
};

#endif // GROUP_H
