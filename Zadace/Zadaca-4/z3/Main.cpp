#include "MojNiz.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  MojNiz<int> a = { 1, 2, 3, 4, 5 };
  // MojNiz<int> b = { 1.1, 2.2, 3.3, 4.4, 5.5 };
  MojNiz<double> c = { 1.1, 2.2, 3.3, 4.4, 5.5 };

  // a = b++;
  std::cout << "A====================A\n";
  c = a;
  std::cout << "B====================B\n";

  // b.push_back(10);
  // a.pop_back();

  // a.print();
  // b.print();
  // c.print();

  return 0;
}
