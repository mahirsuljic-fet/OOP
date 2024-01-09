#include "usefulminifuncs.cpp"
#include <iostream>

template <typename T>
class Foo
{
  public:
    template <typename U>
    Foo(U a);
};

template <typename T>
template <typename U>
Foo<T>::Foo(U a)
{
  std::cout << a << std::endl;
}

int main(int argc, char* argv[])
{
  Foo<int>(1.1);
  Foo<double>(1);
  Foo<int>(1);

  return 0;
}
