#include <iostream>

struct Complex
{
    double r;
    double i;
};

struct Osoba
{
    std::string ime;
    std::string prezime;
};

int main(int argc, char* argv[])
{
  Complex a { 2, 3 };
  auto& r = a.r;

  r = 25;

  std::cout << a.r << std::endl;

  return 0;
}
