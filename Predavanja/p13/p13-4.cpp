#include "MojNiz.hpp"
#include <algorithm>
#include <iostream>
#include <string>

struct Foo
{
    std::string a { "foo" };

    Foo() :
      a { "foo" } { }
    ~Foo() { }
    Foo(const Foo& drugi) :
      a { drugi.a } { }

    Foo(Foo&& drugi) :
      a { std::move(drugi.a) } // da nema move vrsilo bi se kopiranje
    {
      // unutar ovog opsega drugi je trajni objekat!
      // Foo& test = drugi; // validno
    }

    Foo& operator=(const Foo& drugi)
    {
      a = drugi.a;
      return *this;
    }

    Foo& operator=(Foo&& drugi)
    {
      a = std::move(drugi.a);
      return *this;
    }

    Foo(std::string ap) :
      a { ap } { }
};

int main(int argc, char* argv[])
{
  std::string a { "testtesttest" };
  std::string b { "abc" };

  std::cout << sizeof(a) << std::endl;
  std::cout << sizeof(b) << std::endl;
  // a i b su iste velicine jer podaci ("abc" i "testtest...")
  // zive na heap-u, a sizeof uzima velicinu na stack-u

  return 0;
}
