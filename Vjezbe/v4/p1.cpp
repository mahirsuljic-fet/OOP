// Napisati program koji trazi od korisnika unos imena,
// a zatim na ekran ispisuje uokvireno ime sa praznim prostorom
// sirine 2 karaktera.
//
// Primjer:
//
// Unesite ime: Mirza
// **********************
// **********************
// **                  **
// **                  **
// **  Pozdrav Mirza!  **
// **                  **
// **                  **
// **********************
// **********************
//

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  constexpr unsigned short border = 2;
  constexpr unsigned short padding = 2;

  std::string prefix = "Pozdrav ";
  std::string postfix = "!";
  std::string ime;

  std::cout << "Unesite ime: ";
  std::cin >> ime;

  std::string ispis = prefix + ime + postfix;

  int broj_redova = 2 * (border + padding) + 1;
  int broj_kolona = 2 * (border + padding) + ispis.size();

  std::cout << "\n\n"
            << broj_kolona << "\n\n";

  for (int i = 0; i < broj_redova; i++)
  {
    for (int j = 0; j < broj_kolona; j++)
    {
      if (i < border || i >= broj_redova - border || j < border || j >= ispis.size() + 2 * padding + border)
        std::cout << '*';
      else if (i == broj_redova / 2 && j == border + padding)
      {
        std::cout << ispis;
        j += ispis.size() - 1;
      }
      else
        std::cout << ' ';
    }

    std::cout << '\n';
  }

  return 0;
}
