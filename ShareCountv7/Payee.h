#ifndef PAYEE_H
#define PAYEE_H

#include <QString>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include "QStringSerialize.h"

class Payee
{
public:
    typedef int IDType;
    explicit Payee();
    Payee(QString const& name);

    void SetName(QString const& name);
    void SetID(IDType id);
    const QString& GetName() const;
    IDType	GetID() const;

    template <class Archive>
    void serialize(Archive &ar, const int version) {
        ar & m_Name;
        ar & m_ID;
    }

    //bool operator<(const Payee other) const;
    bool operator==(Payee const& other) const;
    bool operator==(IDType id) const;

private:

    QString m_Name;
    IDType	m_ID;

};

bool operator<(Payee const&, Payee const&);

#endif // PAYEE_H
