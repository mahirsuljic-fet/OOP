#include "MojNizInt.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  MojNizInt arr;

  std::cout << arr.capacity() << ": \n";
  arr.print();

  arr.push_back(1);
  std::cout << arr.capacity() << ": ";
  arr.print();

  arr.push_back(2);
  std::cout << arr.capacity() << ": ";
  arr.print();

  arr.push_back(3);
  std::cout << arr.capacity() << ": ";
  arr.print();

  arr.push_back(4);
  std::cout << arr.capacity() << ": ";
  arr.print();

  arr.push_back(5);
  std::cout << arr.capacity() << ": ";
  arr.print();

  MojNizInt p1 = arr;
  MojNizInt p2;
  p2 = arr++;

  p1.print();
  p2.print();
  arr.print();

  return 0;
}
