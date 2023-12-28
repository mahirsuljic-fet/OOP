#include "MojNiz.hpp"
#include <iostream>

// kada vezemo konstantnu referencu za rvalue izraz
// produzujemo mu njegov zivotni vijek

int main(int argc, char* argv[])
{
  // zamislimo ove objekte ispod kao neka ziva bica sa organima
  // m ima svoje organe, n ima svoje organe
  // mozemo klonirat organe (copy konstrukcija) ili transplantirat
  // nema smisla transplantirat iz n u m jer m trebaju njegovi organi
  // medjutim MojNiz{2,3} je privremeni objekat i svejedno ce
  // njegovi organi se unistiti pa ima vise logike da transplatujemo
  // umjesto da kloniramo pa unistimo
  // za ovo ce sluzit implementacija move konstruktora

  MojNiz n { 5, 10, 15 };
  MojNiz m { n };
  MojNiz k { MojNiz { 2, 3 } };

  return 0;
}
