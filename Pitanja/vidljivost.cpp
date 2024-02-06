#include <iostream>

// Da li je moguce zabraniti naslijedjenoj klasi
// da vidi neki clan bazne klase?

class GeometrijskiOblik
{
  protected:
    int broj_stranica;
};

class Trougao : GeometrijskiOblik
{
    int br() { return broj_stranica; }
};

class Krug : GeometrijskiOblik
{
    // krug nema stranica, pa ne treba broj_stranica
};

// Ako ovo nije moguce, koji je najbolji nacin
// da se ovako nesto implementira?
//
// Mozda da se napravi GeometrijskiOblikSaStranicama
// i GeometrijskiOblikBezStranica koji nasljedjuju
// od GeometrijskiOblik od kojih nasljeduju Trougao i Krug
// (s tim da se broj_stranica premjesti u GeometrijskiOblikSaStranicama)?

int main(int argc, char* argv[])
{

  return 0;
}
