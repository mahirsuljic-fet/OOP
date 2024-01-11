#include <iostream>

class Osoba
{
  private:
    std::string ime;

  public:
    Osoba(std::string i) : ime { i } { }
};

struct Student : Osoba
{
  private:
    std::string indeks;

  public:
    Student(std::string im, std::string in)
      : Osoba { im }, indeks { in } { }
};

// prvo se zauzima memorija za clanove koje ima Osoba pa onda Student
//
// inicijaliziraju se clanovi baznog tipa (Osoba)
// okida konstructor baznog tipa (Osoba)
// inicijaliziraju se clanovi naslijedjenog tipa (Student)
// okica konstruktor naslijedjenog tipa (Student)
//
// destrukcija je obrnuto
//
// destrukcija naslijedjenog tipa (Student)
// destrukcija clanova naslijedjenog tipa (Student)
// destrukcija baznog tipa (Osoba)
// destrukcija clanova baznog tipa (Osoba)
//
// vracanje memorije

int main(int argc, char* argv[])
{
  Student foo { "Foo", "234FX5" };

  return 0;
}
