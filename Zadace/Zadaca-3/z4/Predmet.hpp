#pragma once

#include <stdexcept>
#include <string>

struct Predmet
{
    std::string naziv;
    std::string odsjek;

    Predmet(std::string naziv, std::string odsjek)
    {
      if (naziv.size() == 0 || naziv.find_first_not_of(' ') == std::string::npos)
        throw std::domain_error("Predmet ne moze imati prazan naziv!");
      if (odsjek.size() == 0 || odsjek.find_first_not_of(' ') == std::string::npos)
        throw std::domain_error("Predmet ne moze imati prazan odsjek!");

      this->naziv = naziv;
      this->odsjek = odsjek;
    };
};
