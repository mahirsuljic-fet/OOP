// Napisati program koji trazi od korisnika unos broja
// te ukoliko je broj djeljiv sa 3 na ekranu ispisuje Fizz,
// ukoliko je broj djeljiv sa 5 na ekranu ispisuje Buzz
// te ukoliko je broj djeljiv i sa 3 i sa 5, na ekranu se
// ispisuje FizzBuzz. Program se terminira kada korisnik
// unese 0.

#include <iostream>

int main(int argc, char* argv[])
{
  int n;

  std::cout << "Unesite broj: ";
  std::cin >> n;

  while (n != 0)
  {
    if (n % 3 == 0) std::cout << "Fizz";
    if (n % 5 == 0) std::cout << "Buzz";

    std::cout << "\nUnesite broj: ";
    std::cin >> n;
  }

  return 0;
}
