/*!
 * \file User.h
 * \brief Header of User
 *                         */

 #ifndef USER_H
 #define USER_H

#include <QString>
#include <QSharedPointer>
#include <typeinfo>

class User
{

private:
    QString m_login;
    QString m_password;
    QString m_email;


public:

    /*!
     * \brief User
     * \param name
     * \param passw
     * \param email
     */
    User(const QString& name="", const QString& passw="", const QString& email="");

    /*!
     * \brief getId
     * \return
     */
    virtual qlonglong getId() const;

    /*!
     * \brief getLogin
     * \return  le login (username) du membre
     */
    const QString& getLogin() const;

    /*!
     * \brief getPassword
     * \return le mdp du membre
     */
    const QString& getPassword() const;

    /*!
     * \brief getEmail
     * \return  l'email du membre
     */
    const QString& getEmail() const;

    /*!
     * \brief setPassword
     * \param password  changer le mdp
     */
    void setPassword(const QString password);

    /*!
     * \brief ~User destructeur virtuel
     */
    virtual ~User();
    // class User
};



//USER_H INCLUDED
#endif
