#ifndef PERSON_H
#define PERSON_H

#include <QString>
/* inclut les fichiers d'en-tête implémentant une archive dans un format texte basique
sudo apt install -y libboost-all-dev

*/

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

//template function for specialization
/*!
 * base template declaration
 * the idea is to have a base declaration which each class then specialises to its own types
 */
template<class Archive>
/*!
 * \brief serialize : archiver-function that supports several other classes implemented through the project
 * \param ar    reference for the archive
 * \param s     string
 * \param file_version  version_fich
 */
inline void serialize( Archive& ar, QString& s, const unsigned int file_version )
{
    boost::serialization::split_free(ar, s, file_version);
}


template <class Archive>
/*!
 * \brief save  save a member
 * \param ar
 * \param str
 * \param version
 */
void save(Archive& ar, const QString& str, const int version)
{
    ar & str.toStdString();
}

template <class Archive>
/*!
 * \brief load  load a person that has already been serialized
 * \param ar
 * \param str
 * \param version
 */
void load(Archive& ar, QString& str, const int version)
{
    std::string stdstr;
    ar & stdstr;
    str = QString::fromStdString( stdstr );
}

/*!
 * \brief The Person class
 */
class Person
{
public:
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
    Person();

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

private:

    QString m_name;
    IDType	m_ID;

};

#endif
/* PERSON_H included */
