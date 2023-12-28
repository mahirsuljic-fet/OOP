#pragma once

#include "BazaPredmeta.hpp"
#include "Predmet.hpp"
#include <list>
#include <stdexcept>
#include <string>

struct OcjenaIzPredmeta
{
    std::list<Predmet>::const_iterator predmet;
    int ocjena;

    OcjenaIzPredmeta(const int& ocjena, const std::list<Predmet>::const_iterator& predmet)
    {
      if (ocjena < 6 || ocjena > 10) throw std::out_of_range("Ocjena nije validna!");

      this->ocjena = ocjena;
      this->predmet = predmet;
    }

    OcjenaIzPredmeta(const int& ocjena, const std::string& naziv, const BazaPredmeta& baza)
    {
      if (ocjena < 6 || ocjena > 10) throw std::out_of_range("Ocjena nije validna!");

      auto predmet = baza.pronadji(naziv);
      if (predmet == baza.end()) throw std::out_of_range("Predmet ne postoji!");

      this->ocjena = ocjena;
      this->predmet = predmet;
    }
};
