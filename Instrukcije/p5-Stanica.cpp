#include <iostream>

// inace kad se prave uvezane liste koristi se Node kao cvor liste
// moze bit malo zbunjujuce, pa umjesto Node, u ovom primjeru
// ce se koristiti Stanica, kao autobuska stanica
// svaka stanica ima svoj broj i na svakoj pise gdje je sljedeca stanica

struct Stanica
{
    int broj_stanice;
    Stanica* sljedeca;

    Stanica(int n) : broj_stanice(n), sljedeca(nullptr) { }
    Stanica(int n, Stanica* p) : broj_stanice(n), sljedeca(p) { }
};

void dodaj_stanicu_kraj(int n, Stanica*& pocetna)
{
  // ako nema stanica, napravi jednu, reci ovo je pocetna i to je to
  if (pocetna == nullptr)
  {
    pocetna = new Stanica(n);
    return;
  }

  Stanica* trenutna = pocetna;

  // kreni od pocetne stanice i putuj stanicama sve dok
  // ne dodjes do stanice na kojoj ne pise gdje je sljedeca
  // to je zadnja stanica
  while (trenutna->sljedeca != nullptr)
    trenutna = trenutna->sljedeca;

  // kada dodjemo do zadnje, napravit cemo novu stanicu
  // i na onoj zadnjoj cemo napisat gdje je ova nova stanica
  trenutna->sljedeca = new Stanica(n);
}

void dodaj_stanicu_pocetak(int n, Stanica*& pocetna)
{
  // napravimo novu stanicu i na njoj napisemo
  // gdje je pocetna stanica
  Stanica* nova_pocetna = new Stanica(n);
  nova_pocetna->sljedeca = pocetna;
  // ovo dvoje se moze skratiti na
  // Stanica* nova_pocetna = new Stanica(n, pocetna);
  // jer imamo odgovarajuci konstruktor

  // proglasimo ovu novu stanicu pocetnom
  pocetna = nova_pocetna;
}

void ispis_stanica(Stanica*& pocetna)
{
  // ispisujemo brojeve stranica tako sto krenemo od prve
  // ispisemo njen broj, vidimo gdje je sljedeca, odemo na nju,
  // ispisemo njen broj, i sve tako dok ne dodjemo do zadnje stanice
  Stanica* trenutna = pocetna;

  while (trenutna != nullptr)
  {
    std::cout << trenutna->broj_stanice << " ";
    trenutna = trenutna->sljedeca;
  }

  std::cout << std::endl;
}

void izbrisi_stanice(Stanica*& pocetna)
{
  // brisat cemo stanice tako sto izbrisemo prvu, pa drugu, itd.
  // kada izbrisemo prvu, druga nam postaje pocetna
  // zato nismo pravili kopiju (trenutna),
  // ne treba nam, a i svejedno cemo sve izbrisati
  while (pocetna != nullptr)
  {
    // kad bi izbrisali pocetnu (trenutnu) onda ne bi znali gdje je sljedeca,
    // pa moramo napravit kopiju koja ce pamtiti gdje je sljedeca
    Stanica* privremena = pocetna->sljedeca;
    delete pocetna;
    pocetna = privremena;
  }
}

int main(int argc, char* argv[])
{
  Stanica* pocetna = nullptr;

  dodaj_stanicu_kraj(2, pocetna);
  dodaj_stanicu_kraj(3, pocetna);
  dodaj_stanicu_pocetak(1, pocetna);
  dodaj_stanicu_pocetak(0, pocetna);
  dodaj_stanicu_kraj(4, pocetna);

  ispis_stanica(pocetna);
  izbrisi_stanice(pocetna);
  // ako ne izbrisemo stranice ostale bi napustene
  // niko ih ne bi koristio i samo bi zauzimale prostor
  // slicno, ako bi izbrisali samo prvu stranicu,
  // posto nam svaka stanica govori gdje je sljedeca,
  // vise ne bi znali gdje su ostale i ne samo da bi
  // bespotrebno zauzimale mjesto, nego im ne bi mogli
  // vise ni pristupiti
  //
  // ovo se zove curenje memorije (memory leak)

  return 0;
}
