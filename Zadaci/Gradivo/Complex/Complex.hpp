#pragma once

#include <cmath>
#include <iostream>
#include <ostream>

class Complex
{
  public:
    Complex() :
      _re { 0 }, _im { 0 } { }
    Complex(double re, double im) :
      _re { re }, _im { im } { }

    ~Complex() = default;
    Complex(Complex&&) = default;
    Complex(const Complex&) = default;
    Complex& operator=(Complex&&) = default;
    Complex& operator=(const Complex&) = default;

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const;
    Complex operator/(const Complex&) const;

    Complex& operator+=(const Complex& z) { return *this = *this + z; }
    Complex& operator-=(const Complex& z) { return *this = *this - z; }
    Complex& operator*=(const Complex& z) { return *this = *this * z; }
    Complex& operator/=(const Complex& z) { return *this = *this / z; }

    Complex& conjugate();

    double re() const { return _re; }
    double im() const { return _im; }
    double abs() const;
    double arg() const;

    std::ostream& print(std::ostream& os = std::cout, bool brackets = true) const;

  private:
    double _re;
    double _im;
};

Complex conjugate(const Complex&);
bool operator==(const Complex&, const Complex&);
bool operator!=(const Complex&, const Complex&);
std::ostream& operator<<(std::ostream&, const Complex&);
std::istream& operator>>(std::istream&, Complex&);
