#ifndef CONVERTTOAMOUNT_H
#define CONVERTTOAMOUNT_H

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <locale>
#include <sstream>

/*!
 * \brief Amount
 */
typedef
boost::multiprecision::cpp_dec_float_50 Amount;
/**< decimal floating point with fifty digits of accuracy */

template <class char_type>
/*!
 * \brief ConvertToAmount
 * \param in
 * \return
 */
Amount	ConvertToAmount( std::basic_string<char_type> const& in )
{
    std::stringstream stream (in);
    std::ios::iostate state;
    std::locale loc;
    const std::money_get< char_type >& mg = std::use_facet< std::money_get< char_type > >(loc);

    std::basic_string<char_type>	digits;
    typedef typename std::money_get< char_type >::iter_type	iter_type;
    mg.get( stream, iter_type(), false, stream, state, digits);
    if ((state & std::ios::failbit) == std::ios::failbit)
    {
        throw std::runtime_error("Could not convert string to Amount");
    }
    else
    {
        return Amount(digits)/boost::multiprecision::pow( boost::multiprecision::cpp_dec_float_50(10),
        std::use_facet< std::moneypunct< char_type > >(loc).frac_digits() );
    }
}

template <typename T>
/*!
 * \brief ReadAmount
 * \param in
 * \return
 */
Amount	ReadAmount( std::basic_istream<T>& in )
{
    std::ios::iostate state;
    std::locale loc;
    typedef typename std::basic_istream<T>::char_type char_type;
    const std::money_get< char_type >& mg = std::use_facet< std::money_get< char_type > >(loc);

    std::basic_string<char_type>	digits;
    typedef typename std::money_get< char_type >::iter_type	iter_type;
    mg.get( in, iter_type(), false, in, state, digits);
    if ((state & std::ios::failbit) == std::ios::failbit)
    {
        throw std::runtime_error("Could not convert string to Amount");
    }
    else
    {
        return Amount(digits)/boost::multiprecision::pow( Amount(10),
        std::use_facet< std::moneypunct< char_type > >(loc).frac_digits() );
    }
}
#endif
/* CONVERTTOAMOUNT_H included */
