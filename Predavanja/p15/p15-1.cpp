#include <iostream>
#include <string>

struct Profesor
{
    std::string ime;
};

struct Student
{
  private:
    std::string ime;
    Profesor* mentor = nullptr;

  public:
    void dodijeliMentora(Profesor& p) { mentor = &p; }
    Student(std::string s) : ime(s) { }
};

// ako ima smisla da clan klase/strukture egzistira
// bez klase/struktore koristit cemo pointer (npr. moje auto)
// ako nema smisla onda mozemo koristiti bez pointera (npr. moja noga)

int main(int argc, char* argv[])
{
  Profesor foo { "Foo" };
  Student bar { "Bar" };

  bar.dodijeliMentora(foo);

  return 0;
}
