// Mahir Suljic - OOP Zadaca 2023. - Zadatak 8

#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
  srand(time(NULL));

  std::vector<short> balls;
  std::vector<short> chosen;
  std::vector<short> sorted;
  short evenBalls = 0;
  short n = 0;
  short c = 0;

  while (n < 2)
  {
    std::cout << "Unesite ukupan broj kuglica: ";
    std::cin >> n;

    if (n < 2)
      std::cout << "\nUnos nije validan!\nMoraju biti bar dvije kuglice!\n\n";
  }

  while (c <= 0 || c >= n)
  {
    std::cout << "Unesite broj kuglica za izvlacenje: ";
    std::cin >> c;

    if (c <= 0 || c >= n)
      std::cout << "\nUnos nije validan!\n"
                   "Broj kuglica za izvlacenje mora biti pozitivan i manji od ukupnog broja kuglica!\n\n";
  }

  for (short i = 1; i <= n; i++) balls.push_back(i);

  for (short i = 0; i < c; i++)
  {
    short rndIndex = rand() % balls.size();
    chosen.push_back(balls[rndIndex]);
    sorted.push_back(balls[rndIndex]);

    if (balls[rndIndex] % 2 == 0) evenBalls++;

    balls.erase(balls.begin() + rndIndex);
  }

  balls.clear(); // da ne zauzima memoriju

  // bubble sort, jer je najjednostavniji
  bool done = false;
  while (!done)
  {
    done = true;
    for (int i = 0; i < sorted.size() - 1; i++)
    {
      if (sorted[i] > sorted[i + 1])
      {
        short temp = sorted[i];
        sorted[i] = sorted[i + 1];
        sorted[i + 1] = temp;
        done = false;
      }
    }
  }

  std::cout << "Izvuceno\tSortirano\tParni-neparni" << std::endl;

  balls = sorted;
  short printedEven = 0;
  for (int i = 0; i < chosen.size(); i++)
  {
    std::cout << chosen[i] << "\t\t" << sorted[i] << "\t\t";

    for (int j = 0; j < chosen.size(); j++)
    {
      if (printedEven < evenBalls)
      {
        if (balls[j] % 2 == 0)
        {
          std::cout << balls[j];
          balls.erase(balls.begin() + j);
          printedEven++;
          break;
        }
      }
      else if (balls[j] % 2)
      {
        std::cout << balls[j];
        balls.erase(balls.begin() + j);
        break;
      }
    }
    std::cout << std::endl;
  }

  return 0;
}