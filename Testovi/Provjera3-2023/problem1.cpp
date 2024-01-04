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

// alternativa
// template <typename R, typename T, typename U>
// R applyMid(const T& p, const T& k, const U& f)
// ...

template <typename T, typename U>
auto applyMid(const T& p, const T& k, const U& f)
{
  int n = 0;
  T it = p;

  // izbroji elemente
  while (it++ != k) ++n;

  // ako je broj elemenata neparan onda ima samo jedan srednji element
  if (n % 2) throw std::logic_error("There can't be only one middle element!");

  // vrati se na pocetak
  it = p;

  // dodji do prvog srednjeg elementa
  for (int i = 0; i < n / 2 - 1; ++i) ++it;

  // sa alternativnom definicijom funkcije:
  // R a = *it++;
  // R b = *it;
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
    // sa alternativnom definicijom funkcije:
    // int r = applyMid<int>(vec.cbegin(), vec.cend(), f);
    int r = applyMid(vec.cbegin(), vec.cend(), f);
    std::cout << "\nRezultat vektora: " << r << std::endl;

    // sa alternativnom definicijom funkcije:
    // r = applyMid<int>(l.cbegin(), l.cend(), f);
    r = applyMid(l.cbegin(), l.cend(), f);
    std::cout << "Rezultat liste: " << r << std::endl;
  }
  catch (std::logic_error err)
  {
    std::cout << "ERROR: " << err.what() << std::endl;
  }

  return 0;
}
