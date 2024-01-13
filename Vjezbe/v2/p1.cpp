#include <iostream>

int main(int argc, char* argv[])
{
  int a = 5;
  short b = 32765;
  char c = 'V';
  unsigned short d = 1200;

  double e = 5000.2;
  float f = 5000.f;
  bool g = true;

  a = b + 5.5; // 32770

  b = b + 5.; // -32766

  c = c + 4; // Z

  d = d + b; // 33970

  e = e + 0.5777998; //

  f = f + 0.37777f;

  g = g + 4;

  std::cout << "(int) a = " << a << " \t\tsizeof(a) = " << sizeof(a) << std::endl;
  std::cout << "(short) b = " << b << " \t\tsizeof(b) = " << sizeof(b) << std::endl;
  std::cout << "(char) c = " << c << " \t\t\tsizeof(c) = " << sizeof(c) << std::endl;
  std::cout << "(unsigned short) d = " << d << " \tsizeof(d) = " << sizeof(d) << std::endl;
  std::cout << "(double) e = " << e << " \t\tsizeof(e) = " << sizeof(e) << std::endl;
  std::cout << "(float) f = " << f << " \t\tsizeof(f) = " << sizeof(f) << std::endl;
  std::cout << "(bool) g = " << g << " \t\t\tsizeof(g) = " << sizeof(g) << std::endl;

  return 0;
}
