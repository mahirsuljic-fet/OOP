#include <iostream>

struct Foo
{
    int a;

    Foo(int ap) : a { ap } { }
    int operator()(int b)
    {
      return a + b;
    }
};

int main(int argc, char* argv[])
{
  int a = 5;
  // auto f = [a](int b) { return a + b; };
  Foo { a }(8); // isto kao i lambda izraz iznad

  return 0;
}
