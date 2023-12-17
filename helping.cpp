#include <iostream>

struct Foo
{
    char c { 'a' };
    Foo() { std::cout << "Foo1 " << c << std::endl; }
    Foo(char b) :
      c(b) { std::cout << "Foo2 " << c << std::endl; }
    ~Foo() { std::cout << "~Foo " << c << std::endl; }
};

struct Bar
{
    Foo f;
    Bar() { std::cout << "Bar1" << std::endl; }
    Bar(char c) :
      f { c } { std::cout << "Bar2" << std::endl; }
    ~Bar() { std::cout << "~Bar" << std::endl; }
};

void tar1(Bar& b)
{
  std::cout << "tar1 " << b.f.c << std::endl;
}

void tar2(Foo& f)
{
  std::cout << "tar2 " << f.c << std::endl;
}

Bar b('b');
// Foo2 b
// Bar2

int main(int argc, char* argv[])
{
  Bar a;
  // Foo1 a
  // Bar1

  tar1(a);
  // tar1 a

  tar2(b.f);
  // tar2 b

  std::cout << "kraj" << std::endl;

  // ~Bar
  // ~Foo a
  // ~Bar
  // ~Foo b

  return 0;
}
