#include <iostream>

struct Foo
{
    int bar() const { return 100; }

    template <typename T>
    void print(const T& a)
    {
      std::cout << a << std::endl;
    }
};

int main(int argc, char* argv[])
{
  Foo f;

  f.print(5.5);
  f.print("foobar");

  return 0;
}
