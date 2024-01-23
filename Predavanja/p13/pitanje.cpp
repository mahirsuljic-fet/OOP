#include <iostream>

// OVO NIJE POTREBNO ZNANJE U OKVIRU OVOG PREDMETA
// NEGO JE PITANJE STO SAM POSTAVIO PROFESORU

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
// obavezna optimizacija - ne moze se izskljucit od c++17
//
// ne mora znacit da ce kompajler uvijek pozivat move i copy konstruktor
// te nije nuzno dobro da oni proizvode popratne efekte

Foo foo(bool k)
{
  Foo a {}, b {};
  if (k)
    return a;
  else
    return b;
}

Foo bar()
{
  Foo a {};
  return a;
}

Foo test(bool k)
{
  if (k)
    return Foo {};
  else
    return Foo {};
}

int main(int argc, char* argv[])
{
  Foo f1 = Foo {};     // cc edlision
  Foo f2 = foo(true);  // ne moze se izvrsiti cc elision
  Foo f3 = bar();      // moze se izvrsiti cc elision
  Foo f4 = test(true); // moze se izvrsiti cc elision

  return 0;
}
