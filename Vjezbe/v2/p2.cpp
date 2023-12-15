#include <iostream>

int main(int argc, char *argv[])
{
  int a = 5, b = 7;
  double s = 6.;
  float f;
  f = s * (b / 2 + a / 4 << b - a & 0xFF);

  std::cout << "f = " << f << std::endl;

  return 0;
}
