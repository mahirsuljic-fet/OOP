#include "./usefulminifuncs.cpp"
#include <iostream>
#include <vector>

struct Foo
{
    Foo()
    {
      std::cout << "DC\n";
    }

    Foo(const Foo& f)
    {
      std::cout << "DC\n";
    }

    ~Foo()
    {
      std::cout << "D\n";
    }
};

int main(int argc, char* argv[])
{
  Foo a;
  Foo& b { a };

  return 0;
}
