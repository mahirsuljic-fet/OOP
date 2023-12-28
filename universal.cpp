#include "usefulminifuncs.cpp"
#include <iostream>
#include <string>
#include <vector>

struct Foo
{
    int x;

    Foo() = delete;
    Foo(Foo&) = delete;
    Foo(Foo&&) = delete;
    Foo(const Foo&) = delete;
    Foo(const Foo&&) = delete;
    Foo& operator=(const Foo&) = delete;
    Foo& operator=(const Foo&&) = delete;
    Foo& operator=(Foo&) = delete;
    Foo& operator=(Foo&&) = delete;

    Foo(int a) :
      x(a)
    {
      std::cout << "DC - " << x << std::endl;
    }

    ~Foo()
    {
      std::cout << "D - " << x << std::endl;
    }
};

int a = 0;
std::string s = "Test";

int main(int argc, char* argv[])
{
  // Foo { 0 };
  // Foo(1);
  Foo f1 = Foo { 2 };
  // Foo f2 = Foo(3);
  // Foo f3 = 4;
  // int x = Foo(5).x;
  //
  // int a = 5;
  // int* p = &a;
  // int*& pt = p;

  int(((a))) = 5;
  a++;

  std::string t = s;
  std::string(s);
  s = "test";
  std::cout << test << a << std::endl;

  return 0;
}
