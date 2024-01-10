#include <iostream>
#include <string>

struct A
{
    A() { std::cout << 1; }
    A(const A&) { std::cout << 2; }
    A(A&& a) { std::cout << 3; }
    ~A() { std::cout << 9; }
};

struct B
{
    B() { std::cout << 4; }
    B(const B& other) :
      a { std::move(other.a) }
    {
      std::cout << 5;
    }
    B(B&& other) :
      a { std::move(other.a) }
    {
      std::cout << 6;
    }
    ~B() { std::cout << 0; }

  private:
    A a;
};

int main(int argc, char* argv[])
{
  B b1;
  B b2(b1);

  // std::string a = "test";
  // std::string& x = a.append("2"); // a.append() vraca lvalue ref

  // 14250909

  return 0;
}
