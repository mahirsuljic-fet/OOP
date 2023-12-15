#include <iostream>
#include <string>

template <typename T>
T foo(T a, T b);

int main(int argc, char* argv[])
{
  foo(3, 4);
  foo("abc", "def");
  foo(std::string("a"), std::string("b"));
  foo(2, 4.f);
  foo<int>(2, 4.f);
  foo<int>(3, std::string("a"));
  return 0;
}
