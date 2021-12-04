
#include "User.h"
#include <algorithm>



User::User(const QString &name, const QString &passw, const QString &email)
: m_login(name),
m_password(passw),
m_email(email)
{

}

qlonglong User::getId() const
{
// Database is not contain 0 in sequences, see scripts/base.sql
  return 0;
}


const QString& User::getLogin() const
{
  return m_login;
}

const QString& User::getPassword() const
{
  return m_password;
}

const QString& User::getEmail() const
{
  return m_email;
}

void User::setPassword(QString password)
{
  m_password = password;
}

User::~User()
{

}
