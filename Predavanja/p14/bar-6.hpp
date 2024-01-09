#pragma once

#include <string>

template <typename T = int, typename U = std::string>
struct par
{
    T prvi;
    U drugi;

    template <typename A, typename B>
    bool operator==(const par<A, B>& d) const
    {
      return prvi == d.prvi && drugi == d.drugi;
    }
};

template <typename A, typename B>
par<A, B> kreirajPar(A a, B b)
{
  return par<A, B> { a, b };
}
