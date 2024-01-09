#include "bar-3.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  auto a = kreirajPar(5, 'c');
  auto b = kreirajPar(42, 'c');

  std::cout << (a == b) << std::endl;

  return 0;
}
