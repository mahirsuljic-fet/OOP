#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// DZ : umjesto da izbaci iz programa, napravit da trazi ponovni unos

double izracunaj_median(std::vector<double> kontejner)
{
  const auto broj_elemata = kontejner.size();

  if (broj_elemata == 0)
    throw std::runtime_error { "Prazan kontejner nema median!" };

  std::sort(begin(kontejner), end(kontejner));

  const auto sredina = broj_elemata / 2;
  const auto jel_paran = broj_elemata % 2 == 0;
  double median = jel_paran
    ? (kontejner[sredina] + kontejner[sredina - 1]) / 2
    : kontejner[sredina];

  return median;
}

int main()
{
  using namespace std;
  vector<double> k;

  for (double x; std::cin >> x; k.push_back(x))
    ;

  try
  {
    auto median = izracunaj_median(k);
    cout << "m = " << median << endl;
  }
  catch (const runtime_error& e)
  {
    cout << e.what() << endl;
  }

  return 0;
}
