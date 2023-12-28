#pragma once

#include "BazaPredmeta.hpp"
#include "Predmet.hpp"
#include <list>
#include <string>

struct OcjenaIzPredmeta
{
    std::list<Predmet>::const_iterator predmet;
    int ocjena;

    OcjenaIzPredmeta(const int& ocjena, const std::list<Predmet>::const_iterator& predmet);
    OcjenaIzPredmeta(const int& ocjena, const std::string& naziv, const BazaPredmeta& baza);
};
