#ifndef PERSON_H
#define PERSON_H

#include <QString>
/* inclut les fichiers d'en-tête implémentant une archive dans un format texte basique
sudo apt install -y libboost-all-dev

*/

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

#include "QStringSerialize.h"
/*!
 * \brief The Person class
 */
class Person
{
public:
    explicit Person();
    typedef unsigned int IDType;

    /*!
     * \brief Person
     * \param name
     */
    explicit Person(QString const& name);

    /*!
     * \brief Person
     * \param other
     */
    explicit Person(const Person& other);

    /*!
     * \brief Person
     */
    //Person();

    /*!
     * \brief getName
     * \return
     */
    QString getName() const { return m_name; }

    /*!
     * \brief getID
     * \return
     */
    IDType getID() const { return m_ID; }

    template <class Archive>
    /*!
     * \brief serialize
     * \param ar
     * \param version
     */
    void serialize(Archive &ar, const int version) {
        ar & m_name;
        ar & m_ID;
    }

    /*!
     * \brief operator ==
     * \param other
     * \return
     */
    bool operator==(Person const& other);

    /*!
     * \brief operator ==
     * \param id
     * \return
     */
    bool operator==(IDType id);
    void SetName(QString const&);
    void SetID(IDType id);
    //bool operator<(const Person other) const;
private:
    //explicit Person();
    QString m_name;
    IDType	m_ID;

};

bool operator<(const Person&, const Person&);

#endif
/* PERSON_H included */
