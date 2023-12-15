#include "radnik.h"

bool poImenu(const radnik& a, const radnik& b)
{
  return a.ime < b.ime;
}

bool poPlati(const radnik& a, const radnik& b)
{
  return a.plata < b.plata;
}
