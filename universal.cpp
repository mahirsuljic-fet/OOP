#include "usefulminifuncs.cpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <type_traits>

int main(int argc, char* argv[])
{
  std::string i = "test";
  auto x = std::move(i);

  std::cout << std::is_same<decltype(x), std::string>::value << std::endl;
  std::cout << std::is_same<decltype(x), std::string&&>::value << std::endl;

  return 0;
}
