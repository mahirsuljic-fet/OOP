#include <iostream>
#include <string>

struct Complex
{
    double r;
    double i;
};

struct Test
{
    double r;
    char i;
};

struct Osoba
{
    std::string ime;
    std::string prezime;
};

// struktura uvijek zauzima kontinualan komad memorije,
// ali podaci unutar tog kontinualnog bloka memorije
// ne mora nuzno bit kontinualan, (moze imat padding)

int main(int argc, char* argv[])
{
  Complex z { 2, 5 };
  Osoba o { "Mahir", "Suljic" };

  std::cout << sizeof(Complex) << std::endl;
  std::cout << sizeof(Test) << std::endl;

  return 0;
}
