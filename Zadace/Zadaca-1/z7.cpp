// Mahir Suljic - OOP Zadaca 2023. - Zadatak 7

#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::vector<std::string> vec;
  short max = 0;

  while (true)
  {
    std::string s = "";
    std::cout << "Unesi rijec: ";

    char c;
    while ((c = getchar()) != '\n')
      s += c;

    if (s == "")
      break;

    if (s.size() > max)
      max = s.size();

    vec.push_back(s);
  }

  // bubble sort, jer je najjednostavniji
  bool sorted = false;
  while (!sorted)
  {
    sorted = true;
    for (int i = 0; i < vec.size() - 1; i++)
    {
      if (vec[i] > vec[i + 1])
      {
        std::string temp = vec[i];
        vec[i] = vec[i + 1];
        vec[i + 1] = temp;
        sorted = false;
      }
    }
  }

  const short border = 1;
  const short padding = 1;
  for (int i = 0; i < vec.size() + 2 * (border + padding); i++)
  {
    for (int j = 0; j < max + 2 * (border + padding); j++)
    {
      if (i < border || i > vec.size() + border + 2 * padding - 1 || j < border || j > max + border + 2 * padding - 1)
        std::cout << "+";
      else if ((i >= border + padding && i < vec.size() + border + padding) && j == border + padding)
      {
        std::cout << vec[i - border - padding];
        j += vec[i - border - padding].size() - 1;
      }
      else
        std::cout << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}