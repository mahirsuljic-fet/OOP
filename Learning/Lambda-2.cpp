#include "../usefulminifuncs.cpp"
#include <functional>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  auto l = [](int n) { return n + 1; };
  std::vector<int> vec = random_vector_int(10);

  print_container(vec);

  for (auto& el : vec)
    el = l(el);

  print_container(vec);

  return 0;
}
