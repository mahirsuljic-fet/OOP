// Napisati funkciju koja uzima vektor stringova te
// ga transformise na nacin da provjerava da li string
// zavrsava nekim od znakova interpunkcije koji oznacava
// kraj recenice (? ! ili .). Ukoliko string ne zavrsava
// nekim od znakova interpunkcije, dodati tacku na kraj
// stringa.
//

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// implementacija funkcije

void dodavanje_interpunkcije(std::vector<std::string>& vec)
{
  for (auto& s : vec)
    if (s.back() != '?' && s.back() != '!' && s.back() != '.')
      s += '.';
}

int main(int argc, char* argv[])
{
  std::vector<std::string> vec;
  std::string input;
  while (std::getline(std::cin, input))
    vec.push_back(input);
  // pozvati funkciju

  dodavanje_interpunkcije(vec);

  // ispisati sve transformisane elemente

  std::cout << "\nTransformisane recenice:\n";
  for (auto s : vec)
    std::cout << s << std::endl;

  return 0;
}
