#include <functional>
#include <iostream>

const double dx = 0.000001;

double izvod(std::function<double(double)> f, double x)
{
  return (f(x + dx) - f(x)) / dx;
}

double integral(std::function<double(double)> f, double x1, double x2)
{
  double rezultat = 0;

  for (double i = x1; i < x2; i += dx)
    rezultat += f(i) * dx;

  return rezultat;
}

int main(int argc, char* argv[])
{
  double x = 2;
  double x1 = 0;
  double x2 = 2;

  auto f = [](double x) { return x * x; };

  std::cout << "Izvod od x^2 u tacki " << x << " je " << izvod(f, x) << std::endl;
  std::cout << "Integral od x^2 od " << x1 << " do " << x2 << " je " << integral(f, x1, x2) << std::endl;

  return 0;
}
