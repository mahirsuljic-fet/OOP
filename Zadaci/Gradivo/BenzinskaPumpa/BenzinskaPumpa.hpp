#pragma once

#include <iostream>
#include <string>

class BenzinskaPumpa
{
  public:
    BenzinskaPumpa() = delete; // svejedno ga nece biti kad se napravi ovaj ispod, ali posto je navedeno u zadatku nek ostane
    BenzinskaPumpa(const std::string& ime, const std::string& grad, const std::string& adresa)
      : _ime(ime), _grad(grad), _adresa(adresa) { }
    BenzinskaPumpa(BenzinskaPumpa&&);
    BenzinskaPumpa(const BenzinskaPumpa&);
    BenzinskaPumpa& operator=(const BenzinskaPumpa&);
    bool operator<(const BenzinskaPumpa&);
    void postaviCijene(const double& dizel, const double& benzin, const double& lpg);

    std::string ime() const { return _ime; }
    std::string grad() const { return _grad; }
    std::string adresa() const { return _adresa; }
    double dizel() const { return _dizel; }
    double benzin() const { return _benzin; }
    double lpg() const { return _lpg; }
    void ispis(bool cijene = false) const;

  private:
    std::string _ime;
    std::string _grad;
    std::string _adresa;
    double _dizel = 0.0;
    double _benzin = 0.0;
    double _lpg = 0.0;
};
