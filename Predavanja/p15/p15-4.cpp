#include <iostream>

struct Ptica
{
    int krilo;
};

struct Golub : Ptica
{
    int gg;
};

struct Orao : Ptica
{
};

int main(int argc, char* argv[])
{
  Golub golub;
  Orao orao;
  int x;

  Ptica* p = &golub;
  x = p->krilo;

  p = &orao;
  x = p->krilo;

  Ptica& r = golub;
  x = r.krilo;

  r = orao;
  x = r.krilo;

  return 0;
}
