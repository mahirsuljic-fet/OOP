#include "Baza.hpp"
#include "Radnik.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

void BazaRadnika::ucitaj(std::istream stream)
{
  std::string ime;
  double godine;
  double plata;

  while (stream >> ime >> godine >> plata)
    dodaj_radnika(ime, godine, plata);
}

void BazaRadnika::ispisi(std::ostream stream) const
{
  for (const auto& el : _radnici)
    stream << el.ime() << " | " << el.godine() << " | " << el.plata() << std::endl;
}

bool BazaRadnika::dodaj_radnika(std::string ime, double godine, double plata)
{
  for (const auto& el : _radnici)
    if (el.ime() == ime)
      throw std::domain_error("Radnik vec unesen!");

  _radnici.push_back(Radnik(ime, godine, plata));

  return true;
}

bool BazaRadnika::izbrisi_radnika(std::string ime)
{
  for (int i = 0; i < _radnici.size(); i++)
  {
    if (_radnici[i].ime() == ime)
    {
      _radnici.erase(_radnici.begin() + i);
      return true;
    }
  }

  return false;
}

double BazaRadnika::prosjek_plata() const
{
  if (_radnici.size() == 0) return 0;

  double prosjek = 0;

  for (const auto& el : _radnici)
    prosjek += el.plata();

  prosjek /= _radnici.size();

  return prosjek;
}

double BazaRadnika::prosjek_godina() const
{
  if (_radnici.size() == 0) return 0;

  double prosjek = 0;

  for (const auto& el : _radnici)
    prosjek += el.godine();

  prosjek /= _radnici.size();

  return prosjek;
}
