#include <iostream>

class radnik
{
  private:
    std::string _ime;
    double _plata;
    int _godine;
    // _ je konvencija za privatne varijable

  public:
    void povecaj_platu(double);
    void smanji_platu(double);
    std::istream& ucitaj(std::istream&);
    int godina_do_penzije() const; // const - obecajem da necu mijenjat radnika
};

/*
 * inline definicija metoda vs definicija van bloka (non-inline)
 *
 * -implementacija je identicna
 *
 * -trajanje kompajliranja inline metoda traje mnogo duze
 *  od kompajliranja non-inline metoda
 * -non-inline se kompajliraju samo jednom, a inline se kompajliraju
 *  svaki put kad se pozivaju
 * -exe file koji ima puno inline metoda ce biti velik, jer se inline
 *  metode kompajliraju svaki put
 *
 * -inline metode se izvrsavaju mnogo brze nego non-inline metode
 *
 * Zakljucak:
 * -ako imas par linija, slobodno inline
 * -ako imas duzi kod, neke petlje ili nesto, nemoj inline
 */

/*
 *
 */

int main(int argc, char* argv[])
{

  return 0;
}
