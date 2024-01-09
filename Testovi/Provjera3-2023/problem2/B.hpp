#include <iostream>

struct B
{
    B(std::string s)
    {
      std::cout << "3" << s;
    }

    B(const char* s)
    {
      std::cout << "4" << s;
    }

    // void foo() { std::cout << "5"; }
    void foo() const { std::cout << "5"; } // ispravljen kod

    ~B() { std::cout << "9"; }
};
