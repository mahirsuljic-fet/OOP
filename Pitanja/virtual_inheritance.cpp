#include <iostream>

// Sta radi kljucna rijec virtual u ovom kontekstu?
// Da li ima neku drugu korist pored ovoga?

class Bazna
{
  public:
    int a;

  protected:
    Bazna() : a { 0 } { }
};

class Sub1 : virtual public Bazna
{
  public:
    int c;
};

class Sub2 : virtual public Bazna
{
  public:
    int c;
};

class SubSub : Sub1, Sub2
{
  public:
    void foo() { std::cout << a << std::endl; }
};

int main(int argc, char* argv[])
{
  SubSub().foo();

  return 0;
}
