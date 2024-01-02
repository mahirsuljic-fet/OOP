#include <iostream>
#include <iterator>
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
  std::vector<int> brojevi;

  std::cout << "Unesite brojeve:\n";

  std::istream_iterator<int> kraj; // default konstrukcija
  std::istream_iterator<int> it(std::cin); // koristimo std::cin istream
  std::ostream_iterator<int> izlaz(std::cout, " "); // " " ce se ispisat nakon svakog broja

  while (it != kraj) // sve dok je unos validan
  {
    brojevi.push_back(*it);
    ++it;
  }

  auto func = [](int x) { return x > 5; };

  copy_if(brojevi.cbegin(), brojevi.cend(), izlaz, func);
  std::cout << std::endl;

  return 0;
}
