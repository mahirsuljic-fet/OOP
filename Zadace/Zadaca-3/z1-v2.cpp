#include "../../usefulminifuncs.cpp"
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <typename T, typename U>
T filter(const T& collection, U predicate)
{
  T result;

  auto it = std::back_inserter(result);

  for (auto el : collection)
    if (predicate(el))
      it = el;

  return result;
}

int main(int argc, char* argv[])
{
  std::vector<int> vec = { 1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10 };
  std::list<double> list = { 1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10 };

  auto predicate = [](int n) { return n % 2 == 0; };

  vec = filter(vec, predicate);
  list = filter(list, predicate);

  print_container(vec);
  print_container(list);

  return 0;
}
