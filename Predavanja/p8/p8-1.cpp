#include <cmath>
#include <functional>
#include <iostream>

// auto foo(int a)
// {
//   auto f = [a](int b) {
//     return a + b;
//   };
//
//   return f;
// }

typedef std::function<double(double)> F;

auto izvod(F f, double x, const double dx = 0.0001)
{
  return (f(x + dx) - f(x)) / dx;
}

int main(int argc, char* argv[])
{
  // auto fja = foo(10);
  // std::cout << fja(50) << std::endl;

  auto f = [](double x) { return std::sin(x); };

  std::cout << izvod(f, 0) << std::endl;

  return 0;
}
