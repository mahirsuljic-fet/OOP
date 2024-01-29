// Za kod ispod dodati potpunu specijalizaciju strukture Foo
// proizvoljno a zatim instancijari je i parimarnim putem i
// preko specijalizacije unutar main funkcije.
// (ne mogu se sjetiti tacnog teksta ali slicno je ovome,
// kod garantujem da je isti, sto je bitno)

#include <iostream>

template <typename T, typename U>
struct Foo
{
    void foo(T a, U b)
    {
      std::cout << a << b << std::endl;
    }
};

// odgovor

template <>
struct Foo<int, double>
{
    void foo(int a, double b)
    {
      std::cout << "Specijalizacija\n"
                << a << b << std::endl;
    }
};

int main()
{
  Foo<char, bool> a;
  Foo<int, double> b;

  a.foo('a', true);
  b.foo(1, 2.2);

  return 0;
}
