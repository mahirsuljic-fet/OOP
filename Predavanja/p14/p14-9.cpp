#include <iostream>

template <typename T>
struct Foo
{
    struct Bar
    {
    };
};

template <typename A>
void foo()
{
  // ako imamo dependent type mora biti typename
  // ukoliko koristimo genericke tipove
  typename Foo<A>::Bar b;
}

int main(int argc, char* argv[])
{

  return 0;
}
