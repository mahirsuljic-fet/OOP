#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

// napisati funkciju applyMid(p, k, f) koja uzima dva input iteratora i funkciju
// zatim primjenjuje funkciju na srednje elemente kontejnera i vraca rezultat
// nije dozvoljeno koristiti std::distance() i std::advance()
// ukoliko postoji samo jedan srednji element izbaciti iznimku
// std::logic_error("There can't be only one middle element!");
// u main funkciji napisati primjer koristenja funkcije applyMid
// na kontejnerima vector i list, tretirati iznimku

template <typename T, typename U>
auto applyMid(const T& p, const T& k, const U& f)
{
  int n = 0;
  T it = p;

  while (it++ != k) ++n;

  if (n % 2) throw std::logic_error("There can't be only one middle element!");

  it = p;

  for (int i = 0; i < n / 2 - 1; ++i) ++it;

  auto a = *it++;
  auto b = *it;

  return f(a, b);
}

int main(int argc, char* argv[])
{
  std::vector<int> vec;
  std::list<int> l;
  int n;

  std::cout << "Unesite elemente: ";
  while (std::cin >> n)
  {
    vec.push_back(n);
    l.push_back(n);
  }

  auto f = [](int a, int b) { return a + b; };

  try
  {
    int r = applyMid(vec.cbegin(), vec.cend(), f);
    std::cout << "\nRezultat vektora: " << r << std::endl;

    r = applyMid(l.cbegin(), l.cend(), f);
    std::cout << "Rezultat liste: " << r << std::endl;
  }
  catch (std::logic_error err)
  {
    std::cout << "ERROR: " << err.what() << std::endl;
  }

  return 0;
}
