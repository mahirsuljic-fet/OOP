#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>

int foo(int a, int b)
{
  if (b == 0) throw std::runtime_error { "Dijeljenje sa nulom!" };

  return std::sqrt(a) / b;
}

int main(int argc, char* argv[])
{
  int x, y;

  std::cin >> x >> y;

  try
  {
    std::cout << foo(x, y) << std::endl;
  }
  catch (const std::runtime_error& e)
  {
    std::cout << e.what() << std::endl;
  }
  catch (const std::string& e)
  {
    std::cout << "Uhvatio i tretiram iznimku tipa std::string: " << e << std::endl;
  }
  catch (...)
  {
    std::cout << "Tretiram neko iznimno stanje" << std::endl;
  }

  return 0;
}
