#include "Complex.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  Complex z1, z2;

  std::cout << "Unesite prvi kompleksni broj (realni pa imaginarni dio): ";
  std::cin >> z1;
  std::cout << "Unesite drugi kompleksni broj (realni pa imaginarni dio): ";
  std::cin >> z2;

  std::cout << "\nPrvi broj " << z1
            << "\n|z| = " << z1.abs()
            << "\narg{z} = " << z1.arg();
  std::cout << "\n\nDrugi broj " << z2
            << "\n|z| = " << z2.abs()
            << "\narg{z} = " << z2.arg();

  std::cout << "\n\nZbir: " << z1 + z2
            << "\nRazlika: " << z1 - z2
            << "\nProizvod: " << z1 * z2
            << "\nKolicnik: " << z1 / z2;

  std::cout << std::endl;

  return 0;
}
