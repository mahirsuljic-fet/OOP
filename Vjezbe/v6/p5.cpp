// Napisati program koji trazi od korisnika unos rijeci
// te ispisuje unesene rijeci sortirane od Z -> A.

#include "../../usefulminifuncs.cpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<std::string> words;

  std::string word;

  std::cout << "Unesite rijeci: " << std::endl;
  while (std::cin >> word)
    words.push_back(word);

  std::sort(words.begin(), words.end(), [](const std::string& s1, const std::string& s2) -> bool { return s2 < s1; });

  std::cout << std::endl;
  print_container(words, "\n");

  return 0;
}
