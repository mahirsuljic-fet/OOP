#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

// OD i DO su velikim slovima jer je do kljucna rijec u c++
// pa se ne moze koristiti kao ime varijable
template <typename T, typename U, typename V>
void copy_if(const T& OD, const T& DO, U prema, const V& op)
{
  if (!op) throw std::runtime_error("Funkcija nije validna!");

  T it = OD;
  while (it != DO)
  {
    if (op(*it))
      *prema = *it;
    ++it;
  }
}

int main(int argc, char* argv[])
{
  std::cout << "Unesite brojeve:\n";

  std::istream_iterator<int> kraj; // default konstrukcija, pomocu ovog cemo provjeravat validnost unosa
  std::istream_iterator<int> it(std::cin); // koristimo std::cin istream, unosit cemo brojeve (int)
  std::ostream_iterator<int> izlaz(std::cout, " "); // ispisujemo brojeve (int) u os i posle svakog broja " "

  std::vector<int> brojevi(it, kraj);

  // ili "rucno":

  // std::vector<int> brojevi;
  // while (it != kraj) // sve dok je unos validan
  // {
  //   brojevi.push_back(*it);
  //   ++it;
  // }

  auto func = [](int x) { return x > 5; };

  std::cout << std::endl;
  copy_if(brojevi.cbegin(), brojevi.cend(), izlaz, func);
  std::cout << std::endl;

  return 0;
}
