#include <iostream>

struct Foo
{
    Foo operator+(const Foo& b) const;
    Foo operator-() const; // unarni -
    Foo operator+(int); // za a + 2
};

// Foo operator+(const Foo& a, const Foo& b); // isto kao i implementacija kao metoda
// void  operator-(Foo, Foo); // validno, ali sad ne moze npr a - b - c, jer a-b vrati void
Foo operator-(Foo, Foo); // binarni -
Foo operator+(int, Foo); // za 2 + a

int main(int argc, char* argv[])
{
  Foo a, b;
  Foo c = a + b;
  Foo k = -c;
  2 + a;

  return 0;
}
