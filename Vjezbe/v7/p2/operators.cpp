
#include "operators.hpp"
#include "cplx.hpp"

namespace vjezbe08
{

Cplx add(const Cplx& lhs, const Cplx& rhs)
{
  return Cplx { lhs.re + rhs.re, lhs.im + rhs.im };
}

}
