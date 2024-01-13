#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  using namespace std;

  string ime;

  cout << "Unesite ime: ";
  cin >> ime;

  const auto pozdrav = "Pozdrav " + ime + "!";
  const auto duzina = pozdrav.size();

  cout << string(duzina + 4, '*') << endl;
  cout << "* " + string(duzina, ' ') + " *\n";
  cout << "* " + pozdrav + " *\n";
  cout << "* " + string(duzina, ' ') + " *\n";
  cout << string(duzina + 4, '*') << endl;

  return 0;
}
