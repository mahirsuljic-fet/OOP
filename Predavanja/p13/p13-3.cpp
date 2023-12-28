#include "MojNiz.hpp"
#include <algorithm>
#include <iostream>

MojNiz bar(bool t)
{
  MojNiz a { 10, 5 }, b { 13, 4, 5 };
  if (t)
    return a;
  else
    return b;
}

// pravilo sestorki: kad se napravi npr
// struct Foo { int a; };
// compiler pravi 6 metoda
struct Foo
{
    int a;

    Foo() { }
    ~Foo() { }
    Foo(const Foo& drugi) :
      a { drugi.a } { }
    Foo& operator=(const Foo& drugi)
    {
      a = drugi.a;
      return *this;
    }
    // jos move konstruktor i move operator =, pogledaj p13-4.cpp

    // ovaj se takodje pravi u ovom slucaju zbog int a;
    Foo(int ap) :
      a { ap } { }
};

int main(int argc, char* argv[])
{
  // Primjer 1 - COPY =
  // MojNiz m { bar(false) };
  // m = bar(true);
  // m.at(1) = 100;

  // Primjer 2 - MOVE =
  // MojNiz m { 5, 4, -10 };
  // m = bar(false);

  // Primjer 3
  // MojNiz a { 2, 10, -5 }; // MOVE
  // MojNiz b { a }; // COPY

  // Primjer 4
  MojNiz a { 2, 10, -5 };
  MojNiz b { std::move(a) };
  // std::move(a)
  // je isto kao i
  // (MojNiz&&) a
  // pretvara lvalue u rvalue

  a.printaj();
  b.printaj();

  return 0;
}
