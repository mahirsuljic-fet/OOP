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

using grupa = std::vector<std::string>;
using rezultat = std::vector<grupa>;

// const govori korisniku da neces mijenjat njegovu varijablu, ali & se koristi zbog efikasnosti
rezultat napravi_grupe_stringova(const std::vector<std::string>& rijeci)
{
  std::sort(rijeci.begin(), rijeci.end());

  rezultat rez;
  std::string prethodni;

  for (int i = 0; i < rijeci.size(); i++)
  {
    if (rijeci[i] != prethodni)
    {
      rez.push_back(grupa { rijeci[i] });
      prethodni = rijeci[i];
    }
    else
      rez.back().push_back(rijeci[i]);
  }

  return rez;
}

int main(int argc, char* argv[])
{
  std::vector<std::string> rijeci;

  std::cout << "Unesite rijeci:\n";

  std::string s;
  while (std::cin >> s) rijeci.push_back(s);

  rezultat rez = napravi_grupe_stringova(rijeci);

  for (auto r : rez) std::cout << r.front() << ": " << r.size() << std::endl;

  return 0;
}
