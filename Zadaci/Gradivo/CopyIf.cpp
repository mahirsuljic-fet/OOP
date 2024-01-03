#include <iostream>
#include <iterator>
#include <vector>

// prva dva parametra ce biti neki iteratori koji oznacavaju pocetak i kraj
// nekog containera, pa je stavljeno da su oni istog tipa (T)
// treci parametar moze biti back_inserter ili front_inserter
// pa je potrebno da on bude razlicitog tipa (U) od prva dva (T)
// takodjer je bitno da ne uzimamo referencu na back_inserter ili front_inserter
// nego koristimo samo U
// na kraju imamo predikat koji je funkcija te nam treba razlicit tip za njega (V)
// njega mozemo stavit const & kao obecanje da ga necemo mijenjati
// ali sve ovo je ispravno i bez const &, odnosno
// void copy_if(T pocetak, T kraj, U destinacija, V predikat)
// je validno
template <typename T, typename U, typename V>
void copy_if(const T& pocetak, const T& kraj, U destinacija, const V& predikat)
{
  // dali smo obecanje da pocetak necemo dirat sa const
  // pa cemo napravit kopiju koju mozemo pomijerat
  T it = pocetak;

  while (it != kraj)
  {
    if (predikat(*it))
      *destinacija = *it;
    // posto cemo koristiti back_inserter ili front_inserter mozemo
    // jednostavno uraditi *destinacija = *it, inserter ce dodati broj gdje treba

    ++it;
  }
}

int main(int argc, char* argv[])
{
  std::vector<int> brojevi; // vektor u koji cemo spremati unos
  int n;

  std::cout << "Unesite brojeve:\n";
  while (std::cin >> n)
    brojevi.push_back(n);

  // vektor u koji cemo kopirati brojeve vece od 5 (koji zadovoljavaju predikat)
  std::vector<int> kopirani_brojevi;
  auto func = [](int x) { return x > 5; }; // predikat

  // umjesto .cbegin() i .cend() moze .begin() i .end()
  // ovo c ispred oznacava da je to konstantan iterator, tj ne mozemo ga pomijerati
  // posto smo u template of copy_if koristili isti tip (T) i za prvi i za drugi
  // parametar, bitno je da koristimo ili .cbegin() i .cend() ili .begin() i .end()
  // a ne neku kombinaciju, npr .cbegin() i .end() nece kompajlirati
  //
  // kada ovako dodajemo elemente na neku destinaciju najbolje je koristiti
  // back_inserter ili front_inserter, zavisno od toga koji redoslijed zelimo
  // kada koristimo back_inserter ili front_inserter mozemo unutar copy_if funkcije
  // jednostavno uraditi *destinacija = *it
  copy_if(brojevi.cbegin(), brojevi.cend(), std::back_inserter(kopirani_brojevi), func);

  // umjesto const auto& moze i auto ili int
  // ali ovako je malo bolje jer se ne kopiraju brojevi bespotrebno
  for (const auto& broj : kopirani_brojevi)
    std::cout << broj << " ";

  std::cout << std::endl;

  return 0;
}
