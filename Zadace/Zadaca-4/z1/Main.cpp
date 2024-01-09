#include "MojNizInt.hpp"
#include <algorithm>
#include <iostream>

int main(int argc, char* argv[])
{
  MojNizInt p1 = { 1, 2, 3 };
  MojNizInt p2 = p1++;
  p2 = ++p2;

  MojNizInt p3 = p1 * 2 + 2 * p2;

  p2.push_back(2)++;

  p1.print();
  p2.print();

  return 0;
}
