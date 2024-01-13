// Mahir Suljic - OOP Zadaca 2023. - Zadatak 3

#include <iostream>

int main()
{
  short choice = 0;

  while (choice < 1 || choice > 2)
  {
    std::cout << "1. Right triangle check\n"
                 "2. Right triangle list\nYour choice: ";

    std::cin >> choice;

    if (choice < 1 || choice > 2)
      std::cout << "\nInvalid input!\n\n";
  }

  switch (choice)
  {
  // Right triangle check
  case 1:
  {
    int a = 0;
    int b = 0;
    int c = 0;

    // input
    while (true)
    {
      if (a <= 0)
      {
        std::cout << "First triangle side: ";
        std::cin >> a;

        if (a <= 0)
        {
          std::cout << "\nInvalid input!\n\n";
          continue;
        }
      }

      if (b <= 0)
      {
        std::cout << "Second triangle side: ";
        std::cin >> b;

        if (b <= 0)
        {
          std::cout << "\nInvalid input!\n\n";
          continue;
        }
      }

      if (c <= 0)
      {
        std::cout << "Third triangle side: ";
        std::cin >> c;

        if (c <= 0)
        {
          std::cout << "\nInvalid input!\n\n";
          continue;
        }
      }

      break;
    }

    // sort
    if (a > b)
    {
      int temp = a;
      a = b;
      b = temp;
    }
    if (a > c)
    {
      int temp = a;
      a = c;
      c = temp;
    }
    if (b > c)
    {
      int temp = b;
      b = c;
      c = temp;
    }

    if (c * c == a * a + b * b)
      std::cout << "This is a right triangle.\n";
    else
      std::cout << "This is not a right triangle.\n";
  }
  break;
  // Right triangle list
  case 2:
  {
    int n = 0;
    while (n <= 0 || n > 10000)
    {
      std::cout << "Input largest side length (1-10000): ";
      std::cin >> n;

      if (n <= 0 || n > 10000) std::cout << "\nInvalid input!\n\n";
    }

    if (n < 5) std::cout << "There are no right triangles with integer side lengths of which the largest is " << n << " or less.";

    // ako je n<5 petlje se svejedno nece izvrsiti
    for (int i = 5; i <= n; i++)
      for (int j = 4; j <= n; j++)
        for (int k = 3; k <= n; k++)
          if (i * i == j * j + k * k && j > k)
            std::cout << "(" << k << ", " << j << ", " << i << ")" << std::endl;
  }
  break;
  }

  return 0;
}