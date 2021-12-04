#ifndef GROUP_H
#define GROUP_H
#include "Person.h"
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/serialize_ptr_vector.hpp>

/*!
 * \brief The Group class
 * \author
 * classe du modèle representant un groupe d'amis
 */


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

    /*!
     * \brief removeGroupMember
     * \param id
     */
    void removeGroupMember(Person::IDType id);

    /*!
     * \brief size
     * \return la taille du groupe
     */
    unsigned int size() const;

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
    }

private:

    /*!
     * \brief m_groupMembers
     */
    boost::ptr_vector<Person>	m_groupMembers;
};

#endif // GROUP_H
