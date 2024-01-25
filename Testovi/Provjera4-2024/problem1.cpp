#include <algorithm>
#include <iostream>

// Da li se kod ispod kompajlira?
// Ako da, koji je ispis?
// Ako ne, zasto i koji bi ispis bio?

// Ne kompajlira se jer je izbrisan konstruktor A(const A&)
// a poziva se u liniji A a(std::move(idr)), jer std::move()
// ne moze skinuti const te se trazi konstruktor sa const parametrom.

// Eh sad, sto se tice ispisa...
// Nisam siguran na sta se tacno mislilo.
//
// Ako se misli bukvalno u konzoli sta ce ispisati onda je
// "Call to deleted constructor of A" ili "Use of deleted function 'A::A(const A&)'"
//
// Ako se misli da ignorisemo error onda mozemo uzeti da je A(const A&) = default
// pa ce ispis biti 18 (1 zbor new A(), a 8 zbog unistavanja A a iz foo).
// Mozemo takodjer definisati A(const A&) na neki drugi nacin.
// Mozemo izbrisati const iz parametra funkcije foo pa ce se pozivati konstruktor A(A&&).
// Mozemo definisati konstruktor A(const A&&) u kojem slucaju ce on biti pozvan.
//
// Navedeni primjeri su implementirani ispod i zakomentarisani.

class A
{
  public:
    A() { std::cout << 1; };
    A(const A&) = delete;
    A(A&&) : a { 9 } { std::cout << 3; };
    ~A() { std::cout << a; };

    // dodatak:
    // A(const A&) = default; // ispis: 18
    // A(const A&) : a { 4 } { std::cout << 5; } // ispis: 154
    // A(const A&&) : a { 6 } { std::cout << 7; } // ispis: 176, A(const A&) moze ostati izbrisan

  private:
    int a = 8;
};

// void foo(A& idr) // ispis: 139, A(const A&) moze ostati izbrisan
void foo(const A& idr)
{
  A a(std::move(idr));
}

int main(int argc, char* argv[])
{
  foo(*new A());

  return 0;
}
