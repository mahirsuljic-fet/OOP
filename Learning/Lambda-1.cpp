#include "../usefulminifuncs.cpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<int> vec = random_vector_int(100);

  for (int n : vec) std::cout << n << " ";
  std::cout << std::endl;

  std::sort(vec.begin(), vec.end(), [](int x, int y) { return y < x; });

  for (int n : vec) std::cout << n << " ";
  std::cout << std::endl;

  return 0;
}
