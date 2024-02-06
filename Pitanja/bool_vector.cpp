#include <iostream>
#include <vector>

// Zasto se ne moze napraviti pointer na vector<bool>?

int main(int argc, char* argv[])
{
  std::vector<bool> vec_b = { 1, 1, 0, 1 };
  std::vector<int> vec_i = { 1, 1, 0, 1 };

  bool* p_b = &vec_b[0];
  int* p_i = &vec_i[0];

  return 0;
}
