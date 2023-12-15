// Zakljuciti koji je ispis datog programa

#include <iostream>

int main(int argc, char* argv[])
{
  int x = 7;
  int y = -1;

  auto lam = [&x, y](int s) mutable {
    x = x + 5 - s;
    y = s + 3;
    return s + x + y;
  };

  std::cout << lam(1) << " " << x << " " << y << std::endl;

  return 0;
}
