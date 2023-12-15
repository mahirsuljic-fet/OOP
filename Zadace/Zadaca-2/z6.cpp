#include <functional>
#include <iostream>
#include <list>

std::list<int> map(const std::list<int>& list, std::function<int(int)> predicate)
{
  std::list<int> result;

  for (auto el : list)
    result.push_back(predicate(el));

  return result;
}

int main(int argc, char* argv[])
{
  std::list<int> list = { 7, 2, -4, 5, 0, 6, 3 };
  auto f = [](int n) { return n * 2 + 1; };

  list = map(list, f);

  for (auto el : list)
    std::cout << el << ' ';
  std::cout << std::endl;

  return 0;
}
