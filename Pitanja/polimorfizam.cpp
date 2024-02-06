#include <boost/type_index.hpp>
#include <iostream>
#include <string>
#include <vector>

// Uzmimo za primjer sljedece:

struct A
{
    virtual void identify() = 0;
};

struct B : A
{
    void identify() override { std::cout << "B\n"; }
};

struct C : A
{
    void identify() override { std::cout << "C\n"; }
};

void foo()
{
  std::vector<A*> vec;

  vec.push_back(new B());
  vec.push_back(new C());

  for (const auto& el : vec)
    el->identify();
}

// Vjerovatno ne, ali da li postoji nacin da se slicno
// uradi sa compile-time polimorfizmom (template-ima)?
//
// Odnosno, da li je moguce "grupisati" objekte
// napravljene pomocu isto templete-a,
// iako su razlicitih tipova?

template <typename T>
struct temp
{
    void indentify() { std::cout << boost::typeindex::type_id<T>().pretty_name() << std::endl; }
};

void bar()
{
  std::vector<temp> vec;

  vec.push_back(temp<int>());
  vec.push_back(temp<double>());

  for (const auto& el : vec)
    el->identify();
}

int main(int argc, char* argv[])
{
  foo();
  bar();

  // test:
  //
  // temp<int> a;
  // a.indentify();

  return 0;
}
