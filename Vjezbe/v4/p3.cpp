// Napisati program koji od korisnika trazi unos broja recenica.
// Nakon toga korisnik unosi onoliko recenica koliko je naveo,
// te program ispisuje prosjecnu duzinu unesenih recenica.
//
// Primjer:
// Unesite broj recenica: 3
// Unesite recenicu (1/3): Hello world
// Unesite recenicu (2/3): Danas je srijeda
// Unesite recenicu (3/3): Hi
// Prosjecna duzina recenica: 9.66667

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  std::string s {};
  int n {};

  std::cout << "Unesite broj recenica: ";

  if (!(std::cin >> n))
  {
    std::cout << "Unos nije validan!\n";
    return 0;
  }

  std::cin.ignore(1);

  unsigned int zbir {};
  for (int i = 1; i <= n; i++)
  {
    std::cout << "Unesite recenicu (" << i << '/' << n << "):";
    std::getline(std::cin, s);
    zbir += s.size();
  }

  std::cout << "Prosjecna duzina recenica: " << (double)zbir / n << std::endl;

  return 0;
}
