#include <iostream>

int& foo()
{
  int a = 5;
  return a;
}

int g = 5;
int& bar()
{
  return g;
}

struct Foo
{
    int b = 45;
    int& foo() { return b; }
};

int main(int argc, char* argv[])
{
  int& b = foo();
  b = 200;
  // nedefinirano ponasanje
  // jer vracamo referencu na lokalnu varijablu
  // koja nestanje nakon izvrsenja foo()

  int& c = bar();
  c = 10; // ok

  Foo f;
  auto& a = f.foo();
  a = 10; // ok
  // iz metoda se mogu vracati clanovi
  // strukture/klase po referenci

  return 0;
}
