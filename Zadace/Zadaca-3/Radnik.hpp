#pragma once

#include <stdexcept>
#include <string>
class Radnik
{
  private:
    std::string _ime;
    double _godine = 0;
    double _plata = 0;

  public:
    std::string ime() const { return _ime; }
    double plata() const { return _plata; }
    double godine() const { return _godine; }

    Radnik(std::string ime, double godine = 18, double plata = 0)
    {
      if (ime.size() == 0) throw std::domain_error("Radnik mora imati ime!");
      if (godine < 18) throw std::domain_error("Radnik mora biti punoljetan!");
      if (plata < 0) throw std::domain_error("Radnik mora imati nenegativnu platu!");

      _ime = ime;
      _godine = godine;
      _plata = plata;
    }
};
