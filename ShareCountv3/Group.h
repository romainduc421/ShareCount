#ifndef GROUP_H
#define GROUP_H
#include "Person.h"
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/serialize_ptr_vector.hpp>
#include "Recepisse.h"
#include <boost/ptr_container/ptr_map.hpp>
#include <vector>


/*!
 * \brief The Group class
 * \author
 * classe du modèle representant un groupe d'amis
 */

typedef boost::ptr_vector<Recepisse> recepisseCollection;

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
    }

    /*!
     * \brief memberCanBeRemoved
     * \param id
     * \return
     */
    bool	memberCanBeRemoved(Person::IDType id) const;

private:

    /*!
     * \brief m_groupMembers
     */
    boost::ptr_vector<Person>	m_groupMembers;

    /*!
     * \brief m_Collections
     */
    boost::ptr_vector<recepisseCollection>  m_Collections;
};

#endif // GROUP_H
