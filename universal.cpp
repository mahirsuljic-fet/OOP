#include "./usefulminifuncs.cpp"
#include <iostream>
#include <vector>

struct Test
{
    int a;

    Test() { std::cout << "Test1\n"; };
    Test(int x) :
      a { x } { std::cout << "Test2\n"; };
};

int main(int argc, char* argv[])
{
  Test t;

  return 0;
}
