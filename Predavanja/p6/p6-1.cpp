#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  /*
   * ukoliko je cin buffer prazan aktivira se line editor
   * koji parsira uneseni string i sve do praznog prostora
   * stavlja u datu varijablu
   *
   * ukoliko buffer nije prazan u varijablu se unosi sljedeca rijec
   */
  string foo;

  // test test2
  cin >> foo;
  cout << foo << endl;

  cin >> foo;
  cout << foo << endl;

  /* line editor trazi prvu lokaciju koja nije prazno mjesto
   * trazi slova koja su cifre, ako dodje do necega sto
   * nije cifra, tu stane i vec uneseno stavlja u int varijablu
   * u donjem primjeru 234 se unosi u bar, tu stane, onda na drugom
   * cin ide dalje, vidi da t ne moze u int, kaze unos nije uspjesan,
   * u bar ide proizvoljna vrijednost (0, ali nije garantovano da ce biti 0)
   */

  int bar;

  //     234t 18
  cin >> bar;
  cout << bar << endl;

  cin >> bar;
  cout << bar << endl;

  return 0;
}
