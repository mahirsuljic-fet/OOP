#include <algorithm>
#include <iostream>

class B
{
  public:
    B() = default;

    B(B&&) { std::cout << "B&&\n"; };
    B(const B&) { std::cout << "const B&\n"; };
    B(B&) { std::cout << "B&\n"; };
    B(const B&&) { std::cout << "const B&&\n"; };
};

void kod_bez_cout()
{
  // ovaj kod u main-u je malo teze citat zbog silnih ispisa
  // pa evo taj isti kod ali bez cout-ova, da se moze lakse pratiti

  B x1, x2, x3, x4, x5; // pravimo objekte koje cemo koristiti za primjer

  B& lref = x2;                    // pravimo lvalue referencu
  const B& clref = x3;             // pravimo const lvalue referencu
  B&& rref = std::move(x4);        // pravimo rvalue referencu
  const B&& crref = std::move(x5); // pravimo const rvalue referencu

  B a = x1;    // konstrukcija sa B
  B b = lref;  // konstrukcija sa B&
  B c = clref; // konstrukcija sa const B&
  B d = rref;  // konstrukcija sa B&&
  B e = crref; // konstrukcija sa const B&&

  B ma = std::move(x1);    // konstrukcija sa move(B)
  B mb = std::move(lref);  // konstrukcija sa move(B&)
  B mc = std::move(clref); // konstrukcija sa move(const B&)
  B md = std::move(rref);  // konstrukcija sa move(B&&)
  B me = std::move(crref); // konstrukcija sa move(const B&&)
}

int main(int argc, char* argv[])
{
  B x1, x2, x3, x4, x5;

  B& lref = x2;
  const B& clref = x3;
  B&& rref = std::move(x4);
  const B&& crref = std::move(x5);

  std::cout << "DOSTUPNI KONSTRUKTORI:\n"
               "- B(B&&)\n"
               "- B(const B&)\n"
               "- B(B&)\n"
               "- B(const B&&)\n"
               "\n\n";

  std::cout << "     ARGUMENT    |   KONSTRUKTOR\n"
            << "=================|=================\n";

  std::cout << "B\t\t | ";
  B a = x1;
  std::cout << "B&\t\t | ";
  B b = lref;
  std::cout << "const B&\t | ";
  B c = clref;
  std::cout << "B&&\t\t | ";
  B d = rref;
  std::cout << "const B&&\t | ";
  B e = crref;

  std::cout << "-----------------|-----------------\n";

  std::cout << "move(B)\t\t | ";
  B ma = std::move(x1);
  std::cout << "move(B&)\t | ";
  B mb = std::move(lref);
  std::cout << "move(const B&)\t | ";
  B mc = std::move(clref);
  std::cout << "move(B&&)\t | ";
  B md = std::move(rref);
  std::cout << "move(const B&&)\t | ";
  B me = std::move(crref);

  return 0;
}
