// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci std::map.
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
//
// Nakon dobijenog ispisa iznad, izvuci sve kljuceve mape u vektor
// koristeci std::transform iz algorithm zaglavlja te ispisati
// sadrzaj vektora na ekran.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

/*
 * Mapa po defaultu sortira elemente prema <.
 * Moze se kao treci parametar template-a
 * rec kako zelimo da sortira elemente
 */

int main(int argc, char* argv[])
{
  std::map<std::string, int> map;
  std::string s;

  std::cout << "Unesite rijeci: " << std::endl;
  while (std::cin >> s)
    map[s]++;

  for (auto&& el : map)
    std::cout << el.first << " -> " << el.second << '\n';
  std::cout << std::endl;

  std::vector<std::string> keys(map.size());

  std::transform(
    map.cbegin(),
    map.cend(),
    std::back_inserter(keys), // **
    [](std::pair<std::string, int> p) { return p.first; });

  for (auto el : keys)
    std::cout << el << " ";
  std::cout << std::endl;

  return 0;
}
