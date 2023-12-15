// Napisati funkciju koja uzima vektor stringova te
// ga transformise na nacin da provjerava da li string
// zavrsava nekim od znakova interpunkcije koji oznacava
// kraj recenice (? ! ili .). Ukoliko string ne zavrsava
// nekim od znakova interpunkcije, dodati tacku na kraj
// stringa.
//

#include <iostream>
#include <vector>

// implementacija funkcije

int main(int argc, char* argv[])
{
  std::vector<std::string> vec;
  std::string input;
  while (std::getline(std::cin, input))
  {
    vec.push_back(input);
  }
  // pozvati funkciju

  // ispisati sve transformisane elemente

  return 0;
}
