#include <iostream>

int a = 9;
double c;

int main(int argc, char* argv[])
{
  {
    int a = 5;
    short d = 4;
    std::cout << "a = " << a << std::endl;
  }

  std::cout << "a = " << a << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "c = " << c << std::endl;

  {
    char a = 'V';
    float c = 4.f;
    std::cout << "a = " << a << std::endl;
    std::cout << "c = " << c << std::endl;
  }
  return 0;
}
