#include "usefulminifuncs.cpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <type_traits>

int main(int argc, char* argv[])
{
  int i = 0;
  int& i_l = i;
  const int& i_cl = 0;
  int&& i_r = 0;
  const int&& i_cr = 0;

  std::cout << std::is_same<decltype(std::move(i)), int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_l)), int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_cl)), const int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_r)), int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_cr)), const int&&>::value << std::endl;

  return 0;
}
