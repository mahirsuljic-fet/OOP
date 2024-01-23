#include "BenzinskaPumpa.hpp"
#include <algorithm>
#include <stdexcept>

BenzinskaPumpa::BenzinskaPumpa(BenzinskaPumpa&& druga)
{
  _ime = std::move(druga._ime);
  _grad = std::move(druga._grad);
  _adresa = std::move(druga._adresa);

  _dizel = druga._dizel;
  _benzin = druga._benzin;
  _lpg = druga._lpg;

  druga._dizel = 0;
  druga._benzin = 0;
  druga._lpg = 0;
}

BenzinskaPumpa::BenzinskaPumpa(const BenzinskaPumpa& druga)
{
  _ime = druga._ime;
  _grad = druga._grad;
  _adresa = druga._adresa;
  _dizel = druga._dizel;
  _benzin = druga._benzin;
  _lpg = druga._lpg;
}

bool BenzinskaPumpa::operator<(const BenzinskaPumpa& druga)
{
  double zbir_prve = _dizel + _benzin + _lpg;
  double zbir_druge = druga._dizel + druga._benzin + druga._lpg;

  return zbir_prve < zbir_druge;
}

BenzinskaPumpa& BenzinskaPumpa::operator=(const BenzinskaPumpa& druga)
{
  _ime = druga._ime;
  _grad = druga._grad;
  _adresa = druga._adresa;
  _dizel = druga._dizel;
  _benzin = druga._benzin;
  _lpg = druga._lpg;

  return *this;
}

void BenzinskaPumpa::postaviCijene(const double& dizel, const double& benzin, const double& lpg)
{
  if (dizel < 0 || benzin < 0 || lpg < 0)
    throw std::invalid_argument("Cijene nisu validne!");

  _dizel = dizel;
  _benzin = benzin;
  _lpg = lpg;
}

void BenzinskaPumpa::ispis(bool cijene) const
{
  std::cout << "Ime: " << _ime << "\nGrad: " << _grad << "\nAdresa: " << _adresa << std::endl;
  if (cijene) std::cout << "Dizel: " << _dizel << "\nBenzin: " << _benzin << "\nLPG: " << _lpg << std::endl;
}
