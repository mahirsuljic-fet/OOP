#include <iostream>

int a = 10;

namespace ns1 {
  int a = 20;
  namespace ns2 {
    int a = 30;
  }
}

int main (int argc, char *argv[])
{
  int a = 40;
  // Ispisati vrijednost svih varijabli imenovanih "a"

  std::cout << "ns1\t" << ns1::a << std::endl;

  return 0;
}
