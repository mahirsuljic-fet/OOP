#include <iostream>
#include <vector>

void foo(std::vector<std::string> vec) { }
// void foo(const std::vector<std::string>& vec) { }

int main()
{
  std::vector<std::string> vec(100'000'000, "Hello");
  foo(vec);
}
