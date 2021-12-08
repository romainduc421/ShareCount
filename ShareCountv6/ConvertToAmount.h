#ifndef CONVERTTOAMOUNT_H
#define CONVERTTOAMOUNT_H

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <locale>
#include <sstream>
#include <QString>

/*!
 * \brief Amount
 */
typedef
boost::multiprecision::cpp_dec_float_50 Amount;
/**< decimal floating point with fifty digits of accuracy */

Amount
StringToAmount(QString const& string);

#endif
/* CONVERTTOAMOUNT_H included */
