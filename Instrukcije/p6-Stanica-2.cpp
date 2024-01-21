#include <iostream>

struct Stanica
{
    int broj_stanice;
    Stanica* sljedeci;

    Stanica(int n) : broj_stanice(n), sljedeci(nullptr) { }
};

void push_back(Stanica*& pocetna, int broj_nove)
{
  if (pocetna == nullptr)
    pocetna = new Stanica(broj_nove);
  else
  {
    Stanica* kopija_pocetne = pocetna;

    while (kopija_pocetne->sljedeci != nullptr)
      kopija_pocetne = kopija_pocetne->sljedeci;

    Stanica* nova_stanica = new Stanica(broj_nove);
    kopija_pocetne->sljedeci = nova_stanica;
  }
}

void push_front(Stanica*& pocetna, int broj_nove)
{
  Stanica* nova_stanica = new Stanica(broj_nove);
  nova_stanica->sljedeci = pocetna;
  pocetna = nova_stanica;
}

void print(Stanica* pocetna)
{
  while (pocetna != nullptr)
  {
    std::cout << pocetna->broj_stanice << " ";
    pocetna = pocetna->sljedeci;
  }

  std::cout << std::endl;
}

void brisanje(Stanica* pocetna)
{
  while (pocetna != nullptr)
  {
    Stanica* kopija = pocetna;
    pocetna = pocetna->sljedeci;
    delete kopija;
  }
}

int main(int argc, char* argv[])
{
  Stanica* pocetna = nullptr;

  push_back(pocetna, 2);
  push_front(pocetna, 1);
  push_front(pocetna, 0);
  push_back(pocetna, 3);
  push_back(pocetna, 4);

  print(pocetna);
  brisanje(pocetna);

  return 0;
}
