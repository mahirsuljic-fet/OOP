// Mahir Suljic - OOP Zadaca 2023. - Zadatak 9

#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::vector<std::string> vec;
  std::string longest = "";
  int chars = 0;

  /*
    za razliku od zadatka 7, u ovom zadatku je pri unosu
    rijeci implementirana detekcija razmaka
    ukoliko se unese vise rijeci odjednom (sa razmakom)
    tada se te rijeci unose u vektor odvojeno, kao posebne rijeci
  */
 
  while (true)
  {
    std::string s = "";
    std::cout << "Unesi rijec: ";

    char c;
    while ((c = getchar()) != '\n')
      s += c;

    if (s == "")
      break;

    std::string temp = "";
    bool multiWord = false;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] != ' ')
      {
        temp += s[i];
        chars++;
      }
      else
      {
        multiWord = true;
        vec.push_back(temp);

        if (temp.size() > longest.size())
          longest = temp;

        temp = "";
      }
    }

    if (!multiWord)
    {
      if (s.size() > longest.size())
        longest = s;

      vec.push_back(s);
    }
    else
    {
      if (temp.size() > longest.size())
        longest = temp;

      vec.push_back(temp);
    }
  }

  int n = chars < 150 ? chars : 150; // broj znakova '='
  for (int i = 0; i < n; i++)
    std::cout << "=";

  std::cout << "\nLista rijeci\n";

  for (int i = 0; i < vec.size(); i++)
    std::cout << vec[i] << " ";

  std::cout << "\nUkupan broj karaktera: " << chars << std::endl;

  for (int i = 0; i < n; i++)
    std::cout << "=";

  std::cout << "\nNajduza rijec\n";

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < longest.size() + 4; j++)
    {
      if (i == 0 || i == 4 ||
          j == 0 || j == longest.size() + 3)
        std::cout << "+";
      else if (i == 2 && j == 2)
      {
        std::cout << longest;
        j += longest.size() - 1;
      }
      else
        std::cout << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}