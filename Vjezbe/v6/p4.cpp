#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  int x = 7;
  std::function<void()> foo;
  {
    int z = 19;
    foo = [&]() {
      std::cout << x << " " << z << std::endl;
    };
  }

  foo();

  return 0;
}
