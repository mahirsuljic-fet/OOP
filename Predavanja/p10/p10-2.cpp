#include <iostream>
#include <istream>

// struct Foo
// {
//     Foo() = delete;
// };

class Radnik
{
  private:
    std::string _ime;
    double _plata = 0.0;
    int _godine { 0 };

    // ako konstruktor koji se koristi nema npr _plata u listu za inicijalizaciju
    // onda se koristi 0.0, ako ima, koristi se inicijalizacija preko liste

    // int _godine(0); - greska

    // Foo f; - ako je izbrisan kostruktor Foo
    //          napravit ce problem pri procesu konstrukcije Radnika

  public:
    void povecaj_platu(double);
    void smanji_platu(double);
    std::istream& ucitaj(std::istream&);
    int godina_do_penzije() const;

    const std::string& ime() const { return _ime; }
    void ime(const std::string& ulaz) { _ime = ulaz; }

    double plata() const { return _plata; }
    int godine() const { return _godine; }

    // mijenjano ponasanje pri procesu konstrukcije Radnika
    // koristenjem liste za inicijalizaciju
    //
    // redoslijed izvrsenja je po redoslijedu deklaracije varijabli
    //
    // moze bit problem ako se npr koristi _plata pri inicijalizaciji _ime
    //
    // najbolje je listu postaviti u redoslijedu kako su deklarisane varijable
    Radnik() : _plata(0), _godine(0) { } //, _ime("Anoniman") { }

    // Radnik() = delete;
    // Radnik() = default;
    // Radnik(const Radnik&) = delete;

    Radnik(const std::string& ime, int godine, double plata) : _godine(godine), _ime(ime)
    {
      // _ime = ime;
      // _godine = godine;

      if (plata < 0)
        _plata = 0;
      else
        _plata = plata;
    }

    explicit Radnik(std::istream& ulaz);
};

int main(int argc, char* argv[])
{
  Radnik foo { "foo", 2500, 18 };
  Radnik a { std::cin };
  Radnik b(std::cin);
  // Radnik c = std::cin; - error zbog explicit
  Radnik c = Radnik(std::cin);

  return 0;
}
