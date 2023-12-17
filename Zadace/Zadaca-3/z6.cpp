#include "../../usefulminifuncs.cpp"
#include <iostream>

namespace my
{
// insertion sort
template <typename T, typename U>
void sort(const T& p, const T& k, U f)
{
  if (p == k) return;

  T it_main = p;

  while (++it_main != k)
  {
    T it1 = it_main;
    T it2 = it_main;

    --it1;

    while (f(*it1, *it2) && it2 != p)
    {
      auto temp = *it1;
      *it1 = *it2;
      *it2 = temp;

      --it1;
      --it2;
    }
  }
}

template <typename T>
void sort(const T& p, const T& k)
{
  sort(p, k, [](double a, double b) { return a > b; });
}
}

int main(int argc, char* argv[])
{
  std::vector<int> vec = { 21, 42, 5, 25, 24, 10, 21, 20, 27, 42 };

  my::sort(vec.begin(), vec.end()); //, [](int a, int b) { return a < b; });

  print_container(vec);

  return 0;
}
