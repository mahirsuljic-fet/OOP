#include <iostream>
#include <string>

template <typename T, typename U>
struct par
{
    T prvi;
    U drugi;
};

// specijalizacija, moze bit skroz drugacija
// od primarnog template-a
template <> // odavezno
struct par<bool, bool>
{
    // kompajler vrsi optimizaciju da spakuje
    // prvi i drugi u 1B jer oba zauzimaju po 1b
    //
    // B - bajt
    // b - bit
    bool prvi : 1; // : 1 kaze spakuj ovo u 1b
    bool drugi : 1;
};

// djelimicna specijalizacija
// sa skroz drugim kodom
template <typename M>
struct par<M, std::string>
{
  private:
    M a_;

  public:
    par(M a) :
      a_ { a } { }
    M getA() const { return a_; }
};

int main(int argc, char* argv[])
{
  par<bool, bool> a;

  std::cout << sizeof(a) << std::endl;

  // ovo ce biti mnogo sporije zbog onog : 1
  // zrtvujemo performanse za memoriju
  a.drugi = true;
  a.prvi = false;

  par<int, std::string> b { 2 };

  b.getA();

  return 0;
}
