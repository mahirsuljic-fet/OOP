#include <functional>
#include <iostream>
#include <vector>

using Funkcije = std::vector<std::function<bool(int)>>;
void default_if_not_all(std::vector<int>& vec, Funkcije funcs, int def = -1)
{
  for (auto& el : vec)
    for (auto& f : funcs)
      if (!f(el))
        el = def;
}

int main(int argc, char* argv[])
{
  std::vector<int> vec = { 1, 2, 3, 4, 5, 6 };
  Funkcije funcs = {
    [](int n) { return n > 0; },
    [](int n) { return n % 3; },
    [](int n) { return n % 5; }
  };

  default_if_not_all(vec, funcs);

  for (auto n : vec)
    std::cout << n << ' ';
  std::cout << std::endl;

  return 0;
}
