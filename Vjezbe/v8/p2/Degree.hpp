#pragma once

#include "Consts.hpp"
#include "Radian.hpp"

namespace vjezbe10
{

class Degree
{
  public:
    Degree(double value) : value_ { value } { }

    double getValue() const
    {
      return value_;
    }

    void setValue(double value)
    {
      value_ = value;
    }

    double sinus() const
    {
      return sin(value_ * vjezbe10::PI / 180);
    }

    double cosinus() const
    {
      return cos(value_ * PI / 180);
    }

  private:
    double value_;
};

} // namespace vjezbe10
