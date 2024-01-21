#include <algorithm>
#include <iostream>

class A
{
  public:
    A() { std::cout << "A - DC\n"; };
    A(A&&) { std::cout << "A&&\n"; };
    A(const A&) { std::cout << "const A&\n"; };
    // A(A&) { std::cout << "A&\n"; };
    // A(const A&&) { std::cout << "const A&&\n"; };
};

class B
{
  public:
    B() { std::cout << "B - DC\n"; };

    B(B&& other) : a { other.a } { std::cout << "B&&\n\n"; };
    B(const B& other) : a { other.a } { std::cout << "const B&\n\n"; };
    // B(B& other) : a { other.a } { std::cout << "B&\n\n"; };
    // B(const B&& other) : a { other.a } { std::cout << "const B&&\n\n"; };
    //
    // B(B&& other) : a { std::move(other.a) } { std::cout << "B&&\n\n"; };
    // B(const B& other) : a { std::move(other.a) } { std::cout << "const B&\n\n"; };
    // B(B& other) : a { std::move(other.a) } { std::cout << "B&\n\n"; };
    // B(const B&& other) : a { std::move(other.a) } { std::cout << "const B&&\n\n"; };

  private:
    A a;
};

int main(int argc, char* argv[])
{
  B x1, x2, x3, x4, x5;

  std::cout << "\n======================\n\n";

  B& lref = x1;
  const B& clref = x2;
  B&& rref = std::move(x3);
  const B&& crref = std::move(x4);

  std::cout << "DIREKTNO\n\n";

  B a = x1;
  B b = lref;
  B c = clref;
  B d = rref;
  B e = crref;

  std::cout << "\n======================\n\n";
  std::cout << "SA MOVE\n\n";

  B ma = std::move(x1);
  B mb = std::move(lref);
  B mc = std::move(clref);
  B md = std::move(rref);
  B me = std::move(crref);

  return 0;
}
