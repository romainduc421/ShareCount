#ifndef QSTRINGSERIALIZE_H
#define QSTRINGSERIALIZE_H

#include <QString>

template<class Archive>
inline void serialize( Archive& ar, QString& s, const unsigned int file_version )
{
    boost::serialization::split_free(ar, s, file_version);
}

template <class Archive>
void save(Archive& ar, const QString& str, const int version)
{
    std::string stdStr = str.toStdString();
    ar & stdStr;
}

template <class Archive>
void load(Archive& ar, QString& str, const int version)
{
    std::string stdstr;
    ar & stdstr;
    str = QString::fromStdString( stdstr );
}

#endif // QSTRINGSERIALIZE_H
