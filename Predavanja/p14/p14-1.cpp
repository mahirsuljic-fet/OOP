#include <string>

// kad kompajler dodje do template-a nece nista prevodit u masinac
// nego ce samo zapamtit da je vidio template

// ako T ili U nemaju default konstruktor nece ga imati ni par

template <typename T, typename U>
struct par
{
    T prvi;
    U drugi;

    // par() = default;
    // par(const par& d) :
    //   prvi { d.prvi }, drugi { d.drugi } { }
};

// kada se pravi instanca para kompajler kopira kod iz predlozka
// izmisli novo ime za datu strukturu (npr par1, par2, ...)
// i onda zamijeni umjesto par<,> kao npr
// dodje do par<int, double>
// napravi
// struct par1 {
//   int prvi;
//   double drugi;
// };
// i zamjeni par<int, double> sa par1

// od c++17 postoji implicitno instanciranje za genericke tipove
// ali nije toliko korisno i necemo o tome pricat nikako
// uzet cemo da se uvijek radi eksplicitno instanciranje

typedef par<int, double> par1;

int main(int argc, char* argv[])
{
  par<int, double> a;
  par<std::string, float> b;
  par1 c;

  return 0;
}
