#include <iostream>

int main(int argc, char* argv[])
{
  int a = 5, b = 7;

  auto lam = [&a, b](int x) {
    return a * x + b;
  };

  a = 3;
  b = 4;

  std::cout << lam(5) << std::endl;

  return 0;
}
