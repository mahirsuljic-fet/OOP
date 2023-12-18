#include <iostream>

using namespace std;

struct Foo
{
    Foo()
    {
      cout << "DC\n";
    }

    Foo(const Foo&)
    {
      cout << "CC\n";
    }

    ~Foo()
    {
      cout << "D\n";
    }
};

void foo(Foo a)
{
  cout << "Unutar foo\n";
}

Foo a;

int main()
{
  cout << "Pocinjemo\n";
  Foo& b { a };
  cout << "Idemo dalje\n";
  foo(a);
  cout << "Nastavljamo\n";
  Foo {};
  cout << "Zavrsavamo\n";

  return 0;
}
