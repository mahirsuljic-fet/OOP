// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci vektore i std::sort.
//
// Primjer:
//     Unesite rijeci:
//     hi
//     jedan
//     hi
//     dva
//     dva
//     tri
//     hi
//     vjezbe
//     vjezbe
//
//     Frekvencija ponavljanja:
//     dva: 2
//     hi: 3
//     jedan: 1
//     tri: 1
//     vjezbe: 2

#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<std::string> rijeci;

  std::cout << "Unesite rijeci:\n";

  std::string s;
  while (std::cin >> s) rijeci.push_back(s);

  std::sort(rijeci.begin(), rijeci.end());

  int counter = 1;
  std::cout << "\nFrekvencija ponavljanja:\n";

  for (int i = 0; i < rijeci.size() - 1; i++)
  {
    if (rijeci[i] == rijeci[i + 1])
      counter++;
    else
    {
      std::cout << rijeci[i] << ": " << counter << std::endl;
      counter = 1;
    }
  }

  std::cout << rijeci.back() << ": " << counter << std::endl;

  return 0;
}
