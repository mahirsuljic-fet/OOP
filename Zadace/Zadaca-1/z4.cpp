// Mahir Suljic - OOP Zadaca 2023. - Zadatak 4

#include <iostream>
#include <string>

int main()
{
  std::string s1 = "";
  std::string s2 = "";
  int dist = 0;

  do
  {
    std::cout << "Input first string: ";
    std::cin >> s1;
    std::cout << "Input second string: ";
    std::cin >> s2;

    if (s1.size() != s2.size())
      std::cout << "\nStrings must have equal length!\n\n";
  } while (s1.size() != s2.size());

  // pretvori sve u mala slova
  // jer se 'A' i 'a' tretiraju kao isti karakteri
  for (int i = 0; i < s1.size(); i++)
  {
    if (s1[i] >= 'A' && s1[i] <= 'Z')
      s1[i] += 'a' - 'A';

    if (s2[i] >= 'A' && s2[i] <= 'Z')
      s2[i] += 'a' - 'A';

    if (s1[i] != s2[i])
      dist++;
  }

  std::cout << "\nHamming distance is " << dist << ".\n";

  return 0;
}