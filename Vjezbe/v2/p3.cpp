#include <iostream>

int main (int argc, char *argv[])
{
  int a = 0xA, b = 0xC;
  std::cout << (a&b) << std::endl;
  return 0;
}
