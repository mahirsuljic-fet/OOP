#include <iostream>

// apstraktna klasa jer imamo bar jedan cisti virtuelni metod,
// ali je takodjer i interface jer ima SAMO ciste virtuelne metode
struct Ptica
{
    virtual void leti() = 0; // cisti virtuelni metod
};

struct Golub : Ptica
{
    void leti()
    {
      std::cout << "Golub leti\n";
    }
};

// aksiom:
// ako ces nasljedjivat od tipa postavi njegov destruktor kao virtuelni
//
// zasto?

int main(int argc, char* argv[])
{
  // Ptica p; // ne moze jer je Ptica apstraktna klasa
  Golub g;
  Ptica* p;

  p = &g;

  g.leti();
  p->leti();

  return 0;
}
