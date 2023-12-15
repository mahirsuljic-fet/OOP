#include "helpers.hpp"
#include <iostream>

namespace vjezbe08
{

void print(const Cplx& cplx)
{
  std::cout << "(" << cplx.re << " + i" << cplx.im << ")" << std::endl;
}

}
