#include "BazaPredmeta.hpp"
#include "Predmet.hpp"
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

void BazaPredmeta::ispis() const
{
  for (const auto& el : predmeti_)
    std::cout << el.odsjek << " - " << el.naziv << std::endl;
}

const Predmet& BazaPredmeta::dodaj_predmet(
  const std::string& naziv,
  const std::string& odsjek)
{
  if (postoji(naziv))
    throw std::runtime_error("Predmet vec postoji!");

  predmeti_.push_back(Predmet(naziv, odsjek));

  return predmeti_.back();
}

bool BazaPredmeta::izbrisi_predmet(const std::string& naziv)
{
  auto predmet = pronadji(naziv);

  if (predmet->naziv == naziv)
  {
    predmeti_.erase(predmet);
    return true;
  }

  return false;
}

bool BazaPredmeta::postoji(const std::string& naziv) const
{
  for (const auto& el : predmeti_)
    if (el.naziv == naziv)
      return true;

  return false;
}

std::list<Predmet>::const_iterator BazaPredmeta::pronadji(const std::string& naziv) const
{
  for (auto it = this->begin(); it != this->end(); ++it)
    if (it->naziv == naziv)
      return it;

  return this->end();
}

std::list<Predmet>::const_iterator BazaPredmeta::pronadji(const Predmet& predmet) const
{
  for (auto it = this->begin(); it != this->end(); ++it)
    if (it->naziv == predmet.naziv)
      return it;

  return this->end();
}
