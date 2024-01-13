#include "MojNiz.hpp"
#include <algorithm>
#include <iostream>

template <typename T, typename U, typename V>
void print(const MojNiz<T>& a, const MojNiz<U>& b, const MojNiz<V>& c)
{
  std::cout << "a: ";
  a.print();
  std::cout << "b: ";
  b.print();
  std::cout << "c: ";
  c.print();
}

int main(int argc, char* argv[])
{
  MojNiz<int> a = { 1, 2, 3, 4, 5 };
  MojNiz<int> b = { 6.1, 7.1, 8.1, 9.1, 10.1 };
  MojNiz<double> c = { 1.1, 3.3, 5.5, 7.7, 9.5 };

  print(a, b, c);

  std::cout << std::endl;

  std::cout << "\na + c\n";
  (a + c).print();

  std::cout << "\nc + a\n";
  (c + a).print();

  a = c++;

  std::cout << "\na = c++\n";
  print(a, b, c);

  c = a + b;

  std::cout << "\nc = a + b\n";
  print(a, b, c);

  a.pop_back();

  std::cout << "\na.pop_back()\n";
  print(a, b, c);

  b = std::move(a);

  std::cout << "\nb = std::move(a)\n";
  print(a, b, c);

  b.push_back(10);

  std::cout << "\nb.push_back(10)\n";
  print(a, b, c);

  return 0;
}
