#pragma once
#include "Degree.hpp"
#include "Radian.hpp"
#include <cmath>
#include <string>
#include <utility>

namespace vjezbe10
{

class Cplx
{
  public:
    Cplx() = default;
    Cplx(double, Radian);
    Cplx(double, Degree);

    void setReal(double re_) { this->re_ = re_; }
    void setImaginary(double im) { im_ = im; }
    std::string toString() const;

    double modulus() const;

    Radian angle() const;

    Cplx add(const Cplx& other) const;

    Cplx& append(const Cplx& other);

    Cplx makeNegative() const;

  private:
    double re_ = 0.;
    double im_ = 0.;
};

} // namespace vjezbe10
