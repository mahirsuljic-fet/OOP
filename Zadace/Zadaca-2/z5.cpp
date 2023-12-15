#include <functional>
#include <iostream>
#include <list>

std::list<int> filter(const std::list<int>& list, std::function<bool(int)> predicate)
{
  std::list<int> result;

  for (auto el : list)
    if (predicate(el))
      result.push_back(el);

  return result;
}

int main(int argc, char* argv[])
{
  std::list<int> list = { 1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10 };
  auto predicate = [](int n) { return n % 2 == 0; };

  list = filter(list, predicate);

  for (auto el : list)
    std::cout << el << ' ';
  std::cout << std::endl;

  return 0;
}
