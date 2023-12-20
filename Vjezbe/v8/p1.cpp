#include <iostream>

class A
{
  public:
    A() { std::cout << "Default constructor of A\n"; }
    A(int x) { std::cout << "Parameterized constructor of A with value " << x << "\n"; }
    ~A() { std::cout << "Destructor of A\n"; }
};

class B
{
  public:
    B() { std::cout << "Default constructor of B\n"; }
    B(int y) { std::cout << "Parameterized constructor of B with value " << y << "\n"; }
    ~B() { std::cout << "Destructor of B\n"; }
};

// Redoslijed inicijalizacije elemenata objekta je prema
// redoslijedu navodjivanja, a redoslijed "brisanja" je obrnuto

class C
{
    A a;
    B b;

  public:
    C() :
      b(2)
    {
      std::cout << "Constructor of C\n";
    }
    // iznimke koje se generisu u destruktoru
    // se ne mogu uhvatiti van njega
    ~C()
    {
      std::cout << "Destructor of C\n";
    }
};

// g++ -fno-elide-constructors
// ovo kaze kompajleru da ne preskace konstruktore

int main()
{
  C c;
  return 0;
}
