#include <iostream>

struct Foo
{
    Foo() { }
    Foo(const Foo&) { }
    Foo(Foo&&) { }
};

// Da li postoji neki nacin da se provjeri da li je definisan
// neki konstruktor? Ako postoji uradi nesto (npr. ispis).

bool postoji_default;
bool postoji_copy;
bool postoji_move;

int main(int argc, char* argv[])
{
  std::cout << "Dostupni konstruktori:\n";

  if (postoji_default)
    std::cout << "-default\n";
  if (postoji_copy)
    std::cout << "-copy\n";
  if (postoji_move)
    std::cout << "-move\n";

  return 0;
}
