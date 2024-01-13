// Napisati program koji trazi unos broja od korisnika te
// ispisuje da li je broj paran ili neparan.

#include <iostream>

int main(int argc, char* argv[])
{
  int n;

  std::cout << "Unesite neki broj: ";
  std::cin >> n;

  if (n & 1)
    std::cout << "Broj je neparan!" << std::endl;
  else
    std::cout << "Broj je paran!" << std::endl;

  return 0;
}
