#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  using namespace std;

  vector<double> v;
  double x;

  // unos CTRL + D terminira unos, isto kao i da unos nije validan
  // while (cin >> x) v.push_back(x); - moguci nacin unosa

  double suma = 0;
  for (double x; cin >> x; v.push_back(x)) // raucnanje sume unesenih elemenata
    suma += x;

  const auto br_elemenata = v.size();
  if (br_elemenata > 0) {
    sort(v.begin(), v.end());

    const auto srednji_index = br_elemenata / 2;
    auto medijan = br_elemenata % 2
                       ? v[srednji_index]
                       : (v[srednji_index] + v[srednji_index - 1]) / 2;

    // pri koristenju ternarnog operatora uvijek se vraca isti tip
    // ako jedna "grana" daje double a druga int, auto medijan ce biti double

    cout << "Prosjek je " << suma / br_elemenata << endl;
    cout << "Medijan je " << medijan << endl;
  } else
    cout << "Nema elemenata!\n";

  return 0;
}
