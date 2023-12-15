// Napisati program koji od korisnika trazi unos rijeci.
// Nakon toga unesenu rijec ispisuje na satrovackom. :)
//
// Primjer:
// Unesite rijec: nemoj
// mojne
//
// Unesite rijec: zdravo
// vozdra

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  std::string s;
  std::string s_sat;

  std::cout << "Unesite rijec: ";
  std::cin >> s;

  int index = -1;
  for (int i = 0; i < s.size(); i++)
  {
    char c = s[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
      index = i;
      break;
    }
  }

  for (int i = index + 1; i < s.size(); i++)
    s_sat += s[i];

  for (int i = 0; i <= index; i++)
    s_sat += s[i];

  std::cout << s_sat << std::endl;

  return 0;
}
