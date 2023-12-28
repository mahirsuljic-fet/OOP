#include "MojNiz.hpp"
#include <iostream>
#include <ostream>

struct DvaNizaNemajuIstuDimenziju
{
};

MojNiz operator+(MojNiz a, const MojNiz& b)
{
  if (a.size() != b.size()) throw DvaNizaNemajuIstuDimenziju();

  for (auto i = 0; i < a.size(); ++i)
    a.at(i) = a.at(i) + b.at(i);
  return a;
}

std::ostream& operator<<(std::ostream& izlaz, const MojNiz& a)
{
  a.printaj(izlaz);
  return izlaz;
}

int main(int argc, char* argv[])
{
  MojNiz a { 2, 10, -5 };
  MojNiz b { 3, 4, 20 };
  MojNiz c = a + b;

  std::cout << c << std::endl;

  return 0;
}
