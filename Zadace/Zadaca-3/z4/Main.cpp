// Mahir Suljic - OOP Zadaca 3

#include "Generalno.hpp"
#include <iostream>
#include <limits>
#include <string>

#define BROJ_IZBORA_GLAVNI 6

int main(int argc, char* argv[])
{
  int izbor = 0;

  while (izbor >= 0 && izbor <= BROJ_IZBORA_GLAVNI)
  {
    std::cout << "GLAVNI MENI\n\n"
                 "1. unos studenta\n"
                 "2. unos predmeta\n"
                 "3. odabir i izmjena studenta\n"
                 "4. ispis podataka o studenatima\n"
                 "5. ispis studenata, ocijena i prosjeka\n"
                 "6. prosjek (ukupni i po predmetima)\n"
                 "0. izlaz\n\n"
                 "Odaberite opciju: ";

    std::cin >> izbor;
    try
    {
      provjeri_handle_nevalidan_unos();
    }
    catch (std::runtime_error err)
    {
      std::cout << std::endl
                << err.what() << "\n\n";
      continue;
    }

    if (izbor == 0) return 0;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;

    switch (izbor)
    {
    case 1:
      unos_studenta();
      break;
    case 2:
      unos_predmeta();
      break;
    case 3:
      odabir_izmjena_studenta();
      break;
    case 4:
      studenti_podaci();
      break;
    case 5:
      studenti_ocjene();
      break;
    case 6:
      prosjek();
      break;
    default:
      std::cout << "\nIzbor nije validan!\n\n";
      izbor = 0;
    }

    std::cout << std::endl;
  }

  return 0;
}
