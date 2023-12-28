#include "usefulminifuncs.cpp"
#include <iostream>
#include <string>
#include <vector>

struct Foo
{
    Foo()
    {
      std::cout << "DC " << std::endl;
    }

    Foo(const Foo&)
    {
      std::cout << "CC" << std::endl;
    }

    Foo(Foo&&)
    {
      std::cout << "MCC" << std::endl;
    }

    ~Foo()
    {
      std::cout << "D " << std::endl;
    }
};

// copy constuction elision
// zagarantovan od c++17
// obavezna optimizacija - ne moze se izskljucit od 17
//
// ne mora znacit da ce kompajler uvijek pozivat move i copy konstruktor
// te nije nuzno dobro da oni proizvode popratne efekte

int main(int argc, char* argv[])
{
  Foo f = Foo {};

  return 0;
}
