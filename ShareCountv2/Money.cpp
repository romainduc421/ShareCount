#include "Money.h"

#include <cmath>
#include <string>
#include <stdexcept>

Money::Money(const int amount)
{
  int_part = amount;
  real_part = 0;
}

Money::Money(const int int_part, const int real_part)
{
  this->int_part = int_part;
  this->real_part = real_part;
}

std::string Money::to_string() const
{
  return std::to_string(int_part) + "." + std::to_string(real_part);
}

bool Money::operator==(const Money other) const
{
  return (int_part == other.int_part && real_part == other.real_part);
}

bool Money::operator>(const Money other) const
{
  return (int_part > other.int_part) || (int_part == other.int_part && real_part > other.real_part);
}

bool Money::operator<(const Money other) const
{
  return other > *this;
}

bool Money::operator>=(const Money other) const
{
  return *this > other || *this == other;
}

bool Money::operator<=(const Money other) const
{
  return *this < other || *this == other;
}

bool Money::operator!=(const Money other) const
{
    return !(* this == other);
}

Money Money::operator+(const Money other) const
{
  int res_int = int_part;
  int res_real = real_part;

  res_real += other.real_part;
  res_int += res_real / 100;
  res_real %= 100;
  res_int += other.int_part;

  return Money(res_int, res_real);
}

Money Money::operator+(const int other) const
{
  if (real_part + other < 0)
  {
    throw std::invalid_argument("an amount of Money can't be negative");
  }
  return Money(int_part + other, real_part);
}

void Money::operator+=(const Money other)
{

}

Money Money::operator-(const Money other) const
{
  Money res = Money(0, 0);
  if (*this < other)
  {
    throw std::invalid_argument("Money can't have negative value (" + to_string() + "<" + other.to_string() + ")");
  }
  if (other.real_part > real_part)
  {
    res = Money(int_part - other.int_part - 1, (real_part + 100) - other.real_part);
  }
  else
  {
    res = Money(int_part - other.int_part, real_part - other.real_part);
  }
  return res;
}

void Money::operator-=(const Money other)
{
  *this = *this - other;
}
