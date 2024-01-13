#include <iostream>

int main(int argc, char* argv[])
{
  using namespace std;

  int x, y;

  cin >> x >> y;

  /* cin unos zavisi od tipa podatka
   * 5.55 ne moze u int, (bool) cin je false
   * 5.55 moze u double, (bool) cin je true
   * unos 'a' u x odma terminira program i izbaci gresku
   */

  if (cin)
    cout << "Suma x i y je: " << x + y << endl;
  else
    cout << "Pogresan unos!\n";

  return 0;
}
