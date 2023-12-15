#include "radnik.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  radnik Jedan;
  radnik Dva;

  cout << "Unesite ime starost platu za radnika: ";
  cin >> Jedan.ime >> Jedan.starost >> Jedan.plata;
  cout << "Unesite ime starost platu za radnika: ";
  cin >> Dva.ime >> Dva.starost >> Dva.plata;

  vector<radnik> lista_radnika;
  lista_radnika.push_back(Jedan);
  lista_radnika.push_back(Dva);
  sort(begin(lista_radnika), end(lista_radnika), poImenu);

  for (auto k = 0; k < lista_radnika.size(); k++)
    cout << lista_radnika[k].ime << " " << lista_radnika[k].plata << endl;

  return 0;
}
