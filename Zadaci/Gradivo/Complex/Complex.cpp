#include "Complex.hpp"
#include <cmath>
#include <iostream>
#include <ostream>
#include <random>
#include <stdexcept>

Complex Complex::operator+(const Complex& z) const
{
  return Complex(this->_re + z._re, this->_im + z._im);
}

Complex Complex::operator-(const Complex& z) const
{
  return Complex(this->_re - z._re, this->_im - z._im);
}

Complex Complex::operator*(const Complex& z) const
{
  return Complex(
    this->_re * z._re - this->_im * z._im,
    this->_im * z._re + this->_re * z._im);
}

Complex Complex::operator/(const Complex& z) const
{
  double D = z._re * z._re + z._im * z._im;

  if (D == 0) throw std::domain_error("Dijeljenje sa nulom nije dozvoljeno!");

  return Complex(
    (this->_re * z._re + this->_im * z._im) / D,
    (this->_im * z._re - this->_re * z._im) / D);
}

bool operator==(const Complex& z1, const Complex& z2)
{
  if (z1.re() == z2.re() && z1.im() == z2.im())
    return true;
  else
    return false;
}

bool operator!=(const Complex& z1, const Complex& z2)
{
  if (z1.re() != z2.re() || z1.im() != z2.im())
    return true;
  else
    return false;
}

double Complex::abs() const
{
  return std::sqrt(_re * _re + _im * _im);
}

double Complex::arg() const
{
  if (this->_re != 0 && this->_im != 0)
    return std::atan2(this->_im, this->_re);

  if (this->_re != 0 && this->_im == 0)
  {
    if (this->_re > 0)
      return 0;
    else
      return M_PI;
  }

  if (this->_re == 0 && this->_im != 0)
  {
    if (this->_im > 0)
      return M_PI / 2;
    else
      return 3 * M_PI / 2;
  }

  return 0;
}

std::ostream& Complex::print(std::ostream& os, bool brackets) const
{
  if (this->_re == 0 && this->_im == 0) return os << "0";
  if (this->_re == 0) return os << this->_im << "i";
  if (this->_im == 0) return os << this->_re;

  if (brackets) os << "(";
  os << this->_re
     << ((this->_im >= 0) ? " + " : " - ")
     << (this->_im >= 0 ? this->_im : -this->_im) << "i";
  if (brackets) os << ")";

  return os;
}

Complex& Complex::conjugate()
{
  this->_im = -this->_im;
  return *this;
}

Complex conjugate(const Complex& z) { return Complex(z.re(), -z.im()); }

std::ostream& operator<<(std::ostream& os, const Complex& z)
{
  return z.print();
}

std::istream& operator>>(std::istream& is, Complex& z)
{
  double re, im;

  if (is >> re >> im)
    z = Complex(re, im);
  else
    throw std::domain_error("Unos nije validan!");

  return is;
}
