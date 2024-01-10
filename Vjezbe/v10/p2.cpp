#include <iostream>

// sa zavrsnog neke godine

struct A
{
    A() { std::cout << 1; }
    A(const A&) { std::cout << 2; }
    A(A&& a) { std::cout << 3; }
    ~A() { std::cout << 9; }
};

void foo(const A& a0)
{
  A a1(std::move(a0)); // 2

  // poziva se A(const A&) zato jer move ne moze konvertovati
  // const A& u rvalue referencu
}

void bar(A&& a0)
{
  A a1(a0); // 2

  // rvalue referenca je tip, rvalue nije rvalue
  // rvalue referenca nema veze sa lvalue i rvalue
  // rvalue referenca je lvalue, zato se poziva A(const A&)

  // A a1(a0); // 3
  // move sluzi sa ovakve namjene
}

int main(int argc, char* argv[])
{
  foo(A {}); // 1
  // 99
  bar(A {}); // 1
  // 99

  // 12991299

  return 0;
}
