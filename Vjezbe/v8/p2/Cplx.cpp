#include "Cplx.hpp"
#include <cmath>

namespace vjezbe10
{

Cplx::Cplx(double r, Radian f)
{
  this->re_ = r * f.cosinus();
  this->im_ = r * f.sinus();
}

Cplx::Cplx(double r, Degree f)
{
  this->re_ = r * f.cosinus();
  this->im_ = r * f.sinus();
}

std::string Cplx::toString() const
{
  return std::to_string(re_) + "+" + std::to_string(im_) + std::string("i");
}

double Cplx::modulus() const
{
  return std::sqrt(this->re_ * this->re_ + this->im_ * this->im_);
}

Radian Cplx::angle() const
{
  return Radian(std::atan2(this->im_, this->re_));
}

Cplx Cplx::add(const Cplx& other) const
{
  return Cplx((double)(this->re_ + other.re_), (double)(this->im_ + other.im_));
}

Cplx& Cplx::append(const Cplx& other)
{
  this->re_ += other.re_;
  this->im_ += other.im_;

  return *this;
}

Cplx Cplx::makeNegative() const
{
  Cplx rez(*this);

  if (this->re_ > 0)
    rez.re_ = -rez.re_;
  if (this->im_ > 0)
    rez.im_ = -rez.im_;

  return rez;
}

} // namespace vjezbe10
