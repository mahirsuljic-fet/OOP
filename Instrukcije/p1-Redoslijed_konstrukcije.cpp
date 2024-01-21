#include <iostream>
#include <string>

struct Foo
{
    // a ce se uvijek konstruisati prije s, jer se deklarisan prije s
    // stoji tu cisto za primjer, nismo ga koristili nigdje
    std::string a = "uvijek prvi";
    std::string s = "1";

    Foo()
    {
      std::cout << "|" << s << "|" << std::endl;
    }

    Foo(int)
    {
      std::cout << "|" << s << "|" << std::endl;
      s = "2";
    }

    Foo(bool) : s { "3" }
    {
      std::cout << "|" << s << "|" << std::endl;
    }

    Foo(char) : s { "4" }
    {
      std::cout << "|" << s << "|" << std::endl;
      s = "5";
    }
};

// prvo se inicijalizacija vrsi preko liste za inicijalizaciju
// ako je nema, onda se vrsi kako je navedeno u definiciji clanova strukture/klase
// ako pri definiciji clanova oni nisu inicijalizirani nego samo deklarisani
// koristit ce se njihov default konstruktor, primitivni tipovi se ne inicijaliziraju
// nakon toga se izvrsava tijelo konstruktora

int main(int argc, char* argv[])
{
  Foo a;
  Foo b(0);
  Foo c(true);
  Foo d('a');

  std::cout << a.s << std::endl;
  std::cout << b.s << std::endl;
  std::cout << c.s << std::endl;
  std::cout << d.s << std::endl;

  return 0;
}
