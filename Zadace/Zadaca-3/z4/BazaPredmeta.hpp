#pragma once

#include "Predmet.hpp"
#include <list>
#include <string>

class BazaPredmeta
{
  private:
    std::list<Predmet> predmeti_;

  public:
    void ispis() const;
    const Predmet& dodaj_predmet(const std::string& naziv, const std::string& odsjek);
    bool izbrisi_predmet(const std::string& naziv);
    bool postoji(const std::string& naziv) const;
    std::list<Predmet>::const_iterator pronadji(const std::string& naziv) const;
    std::list<Predmet>::const_iterator pronadji(const Predmet& predmet) const;
    std::list<Predmet>::const_iterator begin() const { return predmeti_.begin(); }
    std::list<Predmet>::const_iterator end() const { return predmeti_.end(); }
};
