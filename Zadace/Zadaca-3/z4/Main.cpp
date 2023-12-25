// Mahir Suljic - OOP Zadaca 3

#include <iostream>
#include <limits>
#include <string>

#define BROJ_IZBORA_GLAVNI 6

void unos_studenta();
void unos_predmeta();
void odabir_izmjena_studenta();
void prosjek();
void studenti_podaci();
void studenti_ocjene();

void student_promijeni_broj_indeksa(std::string broj_indeksa);
void student_promijeni_ime(std::string broj_indeksa);
void student_promijeni_prezime(std::string broj_indeksa);
void student_promijeni_grad(std::string broj_indeksa);
void student_dodavanje_ocjene(std::string broj_indeksa);

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

    if (!(std::cin >> izbor))
    {
      if (std::cin.eof())
      {
        std::cout << std::endl;
        return 0;

        //   std::cin.clear();
        //   std::clearerr(stdin);
        //   continue;
      }

      std::cout << "\nIzbor nije validan!\n\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
