#include <iostream>

int main (int argc, char *argv[])
{
  auto a = 4+4*4<<4;
  std::cout << a << std::endl;
  auto b = 4+4*(4<<4);
  std::cout << b << std::endl;
  auto c = a+4.5*2+(0xA & 0xB);
  std::cout << c << std::endl;
  std::cout << sizeof(c) << std::endl;
  return 0;
}
