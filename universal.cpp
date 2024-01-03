#include "usefulminifuncs.cpp"
#include <algorithm>
#include <iostream>
#include <string>

struct Foo
{
    std::string a;

    Foo() :
      a { "" } { std::cout << "DC -> " << a << std::endl; }

    Foo(std::string s) :
      a { s } { std::cout << "DC{s} -> " << a << std::endl; }

    ~Foo() { std::cout << "D -> " << a << std::endl; }

    Foo(const Foo& f) :
      a { f.a } { std::cout << "CC -> " << a << std::endl; }

    Foo(Foo&& f) :
      a { std::move(f.a) } { std::cout << "MC -> " << a << std::endl; }

    Foo& operator=(const Foo& f)
    {
      a = f.a;
      std::cout << "COPY=\n";
      return *this;
    }

    Foo& operator=(Foo&& f)
    {
      a = std::move(f.a);
      std::cout << "MOVE=\n";
      return *this;
    }

    Foo& operator=(const std::string&& s)
    {
      a = std::move(s);
      std::cout << "MOVE_s=\n";
      return *this;
    }
};

// Foo bar(bool t)
// {
//   Foo a { "a" }, b { "b" };
//   if (t)
//     return a;
//   else
//     return b;
// }

int main(int argc, char* argv[])
{
  Foo a { "a" };
  Foo b { "b" };

  a = std::move(b);

  std::cout << "|" << b.a.empty() << "|" << std::endl;

  return 0;
}
