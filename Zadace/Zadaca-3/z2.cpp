#include "../../usefulminifuncs.cpp"
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename T, typename U>
T map(const T& collection, U transform)
{
  T result;
  auto it = std::back_inserter(result);

  for (auto el : collection)
    it = transform(el);

  return result;
}

int main(int argc, char* argv[])
{
  std::vector<int> vec = { 7, 2, -4, 5, 0, 6, 3 };
  std::list<int> list = { 7, 2, -4, 5, 0, 6, 3 };

  auto t = [](int n) { return n * 2 + 1; };

  vec = map(vec, t);
  list = map(list, t);

  print_container(vec);
  print_container(list);

  return 0;
}
