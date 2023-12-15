#include <algorithm>
#include <array>
#include <iostream>

template <std::size_t N>
void printArray(std::array<int, N> arr)
{
  for (auto i : arr) std::cout << i << ' ';
  std::cout << '\n';
}

int main(int argc, char* argv[])
{
  std::array<int, 10> b { 0 };

  for (int i = 0; i < b.size(); i++)
    b[i] = i + 1;

  printArray(b);
  b = { 0 };

  int n = 1;
  for (auto i = b.begin(); i != b.end(); i++)
    *i = n++;

  printArray(b);

  b = { 0 };
  n = 1;

  for (auto& i : b) i = n++;

  printArray(b);

  std::fill(b.begin(), b.end(), 0);

  printArray(b);

  b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  printArray(b);

  return 0;
}
