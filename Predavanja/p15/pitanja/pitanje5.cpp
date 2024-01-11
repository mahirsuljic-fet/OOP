#include <iostream>

// PRIMJER ZA UPOREDBU

struct Foo
{
  public:
    virtual void f() { std::cout << "Foo\n"; }
};

struct Foo1 : Foo
{
  public:
    void f() { std::cout << "Foo1\n"; }
};

struct Foo2 : Foo
{
  public:
    void f() { std::cout << "Foo2\n"; }
};

void primjer1()
{
  Foo* arr[] = { new Foo(), new Foo1(), new Foo2() };

  for (const auto& el : arr)
    el->f();

  for (auto& el : arr) delete el;
}

//=======================================================================================//
//                                     PITANJE 5                                         //
//=======================================================================================//

// da li je moguce uraditi slicno sa generickim klasama?

template <typename T>
struct Bar
{
    void f() { std::cout << "Bar size: " << sizeof(T) << std::endl; }
};

void primjer2()
{
  // Bar* arr[] = { new Bar<int>(), new Bar<double>(), new Bar<char>() };
  //
  // for (const auto& el : arr)
  //   el->f();
  //
  // for (auto& el : arr) delete el;
}

int main(int argc, char* argv[])
{
  primjer1();
  primjer2();

  return 0;
}
