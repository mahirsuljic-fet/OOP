#include "bar-5.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  par<int, char> a = kreirajPar(65, 'c');
  par<char, char> b = kreirajPar('A', 'c');

  // a == b je ekvivalentno a.operator==(b)
  std::cout << (a == b) << std::endl;

  return 0;
}
