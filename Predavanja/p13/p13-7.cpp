#include <iostream>

struct Foo
{
    void operator()(int, const char*)
    {
      std::cout << "foobar" << std::endl;
    }
};

int main(int argc, char* argv[])
{
  Foo o;
  o(2, "test");

  return 0;
}
