#include "B.hpp"
#include <iostream>

const std::string P = "P3";
struct A
{
    A() :
      b2 { "xyz" }, b1 { P }
    {
      std::cout << "1";
    }

    void foo() const
    {
      b1.foo();
      std::cout << "2";
    }

    ~A() { std::cout << "0"; }

  private:
    B b1 { "abc" };
    B b2 { P };
};
