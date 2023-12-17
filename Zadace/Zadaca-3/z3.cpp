#include <iostream>
#include <vector>

template <typename T, typename U>
double reduce(const T& collection, U func, double start)
{
  for (auto el : collection)
    start = func(start, el);

  return start;
}

int main(int argc, char* argv[])
{
  std::vector<int> vec = { 11, 4, 5, 12, 6, 8, 9 };

  auto f = [](int a, int b) { return a + b + 1; };

  std::cout << reduce(vec, f, -12) << std::endl;

  return 0;
}
