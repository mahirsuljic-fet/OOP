#pragma once

#include "Radnik.hpp"
#include <iostream>
#include <string>
#include <vector>

class BazaRadnika
{
  public:
    void ucitaj(std::istream& stream);
    void ispisi(std::ostream& stream) const;
    bool dodaj_radnika(std::string ime, double godine = 18, double plata = 0);
    bool izbrisi_radnika(std::string ime);
    double prosjek_plata() const;
    double prosjek_godina() const;

  private:
    std::vector<Radnik> _radnici;
};
