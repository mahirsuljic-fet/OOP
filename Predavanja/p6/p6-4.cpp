#include <iostream>
#include <vector>

// typedef int Foo;
// typedef double BAM;
// typedef double USD;
//
// Foo a = 5;

int main(int argc, char* argv[])
{
  using namespace std;

  int a = 5;
  int b { a }; // copy konstrukcija
  int& c { a }; // & - ref
  double d = b;
  double& e = d;

  // referenca je drugo ime za varijablu koju referenciramo
  // ref nema veze sa pointerima, ima ref kod pointera ali nije to to
  // auto ne preuzima ref, auto x{c} je samo nova varijabla tipa int
  // moze se koristiti const uz ref, ali se ne moze mijenjat vrijednost
  // referencirane varijable
  // const int& x = b;
  // x = 2; // error

  cout << "a | b | c | d | e\n-----------------\n";
  cout << a << " | " << b << " | " << c << " | " << d << " | " << e << endl;

  a = 2;

  cout << a << " | " << b << " | " << c << " | " << d << " | " << e << endl;

  c++;

  cout << a << " | " << b << " | " << c << " | " << d << " | " << e << endl;

  b = 8;

  cout << a << " | " << b << " | " << c << " | " << d << " | " << e << endl;

  e = 9;

  cout << a << " | " << b << " | " << c << " | " << d << " | " << e << endl;

  return 0;
}
