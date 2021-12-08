#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#ifndef MONEY_H
#define MONEY_H

/*!
 * \brief The Money class
 */

class Money
{
  private:
    unsigned int int_part;  /**< euros part */
    unsigned int real_part; /**< cents part */

  public:
    /*!
     * \brief Money
     * \param amount
     */
    Money(const int amount);

    /*!
     * \brief Money
     * \param int_part
     * \param real_part
     */
    Money(const int int_part, const int real_part);

    // operateurs triviaux
    std::string to_string() const;

    bool operator==(const Money other) const;
    bool operator>(const Money other) const;

    bool operator<(const Money other) const;
    bool operator>=(const Money other) const;
    bool operator<=(const Money other) const;
    bool operator!=(const Money other) const;

    Money operator+(const Money other) const;
    Money operator+(const int other) const;

    void operator+=(const Money other);

    Money operator-(const Money other) const;

    void operator-=(const Money other);

    std::vector<Money> operator/(const int other);
};


#endif // MONEY_H_INCLUDED
