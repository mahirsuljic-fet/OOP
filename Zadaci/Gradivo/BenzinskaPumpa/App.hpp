#pragma once

#include "BenzinskaPumpa.hpp"
#include <string>
#include <vector>

class App
{
  public:
    std::vector<BenzinskaPumpa> pretrazi(const std::string& grad);
    BenzinskaPumpa& najjeftinija();
    BenzinskaPumpa& najjeftinija(const std::string& grad);
    BenzinskaPumpa& najjeftinija_tip_goriva(const std::string& tip_goriva);
    void dodaj_pumpu(const std::string& ime, std::string grad, std::string adresa);
    void obrisi_pumpu(const std::string& ime, std::string grad);
    void ispis(bool cijene = false) const;
    ~App();

  private:
    std::vector<BenzinskaPumpa> _pumpe;
};
