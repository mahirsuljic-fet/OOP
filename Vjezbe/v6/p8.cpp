// Napisati program koji trazi od korisnika unos rijeci.
// Korisnik prekida unos kada unese EOF karakter.
// Nakon unesenih rijeci program ispisuje frekvenciju ponavljanja
// svake od unesenih rijeci.
//
// Program rijesiti koristeci vektore, std::sort i strukture.
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
//     hi: 3
//     jedan: 1
//     dva: 2
//     tri: 1
//     vjezbe: 2
//

#include <iostream>
#include <string>
#include <vector>

struct Evidencija
{
    std::string rijec;
    int frekvencija = 0;
};

int find_rijec(const std::vector<Evidencija>& vec, const std::string& s)
{
  for (int i = 0; i < vec.size(); i++)
    if (vec[i].rijec == s)
      return i;

  return -1;
}

int main(int argc, char* argv[])
{
  std::vector<Evidencija> vec;
  std::string s;

  std::cout << "Unesite rijeci: " << std::endl;
  while (std::cin >> s)
  {
    auto index = find_rijec(vec, s);
    if (index == -1)
      vec.push_back(Evidencija { s, 1 });
    else
      vec[index].frekvencija++;
  }

  for (auto e : vec)
    std::cout << e.rijec << ": " << e.frekvencija << std::endl;

  return 0;
}
