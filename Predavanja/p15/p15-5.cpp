#include <iostream>

struct Ptica
{
    virtual void leti()
    {
      std::cout << "Ptica leti\n";
    }
};

struct Golub : Ptica
{
    void leti()
    {
      std::cout << "Golub leti\n";
    }
};

// pri pozivu metode ako se ne kaze drugacije kompajler pogleda
// objekat i trazi u njemu metod koji se poziva
// dakle ako nema virtual, p->leti() poziva
// leti() od Ptica jer je p pointer tipa Ptica
// ako u Golub nema override-an metod leti()
// poziva se leti() od Ptica

// runtime polimorfizam
void foo(Ptica* p) { p->leti(); }

// compile-time polimorfizam
template <typename T>
void bar(T a) { a.leti(); }

// runtime polimorfizam je skuplji po pitanju performansi
// tako da koristimo compile-time polimorfizam kad nam runtime ne treba

// u c++ je ovako, ali npr. u C# i Javi svi metodi su po default-u virtuelni

int main(int argc, char* argv[])
{
  Golub golub;
  golub.leti();

  Ptica* p = &golub;
  p->leti();

  foo(&golub);
  foo(p);

  return 0;
}
