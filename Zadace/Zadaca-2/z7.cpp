#include <functional>
#include <iostream>
#include <list>

int reduce(const std::list<int>& list, std::function<int(int, int)> func, int start = 0)
{
  for (auto el : list)
    start = func(start, el);

  return start;
}

int main(int argc, char* argv[])
{
  std::list<int> list = { 11, 4, 5, 12, 6, 8, 9 };
  auto f = [](int a, int b) { return a + b + 1; };
  int start = -12;

  std::cout << reduce(list, f, start) << std::endl;

  return 0;
}
