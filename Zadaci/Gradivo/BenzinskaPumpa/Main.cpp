#include "App.hpp"
#include "BenzinskaPumpa.hpp"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// uradjen je vise manje minimum sto se trazi u zadatku plus npr ispis
// App ima nedostataka, npr ne moze se mijenjati cijena goriva,
// ali to nije trazeno u zadatku

int main(int argc, char* argv[])
{
  App app;

  app.dodaj_pumpu("Kopex", "Tuzla", "adresa1");
  app.dodaj_pumpu("Belamionix", "Srebrenik", "adresa2");
  app.dodaj_pumpu("Gazprom", "Tuzla", "adresa3");
  app.dodaj_pumpu("HIFA", "Srebrenik", "adresa4");
  app.dodaj_pumpu("IN VIVO", "Ljepunice", "adresa5");
  app.dodaj_pumpu("Kopex", "Srebrenik", "adresa6");

  app.obrisi_pumpu("Kopex", "Srebrenik");

  app.ispis();

  std::vector<BenzinskaPumpa> tuzla = app.pretrazi("Tuzla");

  std::uniform_real_distribution<double> unif(1, 3); // za random brojeve, ignorisati
  std::default_random_engine re;                     // za random brojeve, ignorisati

  for (auto& pumpa : tuzla)
    pumpa.postaviCijene(unif(re), unif(re), unif(re)); // gorivo dobija random vrijednost izmedju 1 i 3

  for (const auto& pumpa : tuzla) // ispis pumpa u Tuzli sa novim cijenama goriva
  {
    pumpa.ispis(true);
    std::cout << std::endl;
  }

  return 0;
}
