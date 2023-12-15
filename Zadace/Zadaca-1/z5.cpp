// Mahir Suljic - OOP Zadaca 2023. - Zadatak 5

#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;

  long long n = 0;
  int sum = 0;
  long prod = 1;
  short max = 0;
  short min = 9;

  while (n <= 0)
  {
    std::cout << "Input a positive integer: ";
    std::cin >> n;

    if (n <= 0)
      std::cout << "\nInvalid input!\n\n";
  }

  while (n > 0)
  {
    short temp = n % 10;

    if (temp < min) min = temp;
    if (temp > max) max = temp;

    sum += temp;
    prod *= temp;

    vec.push_back(temp);

    n /= 10;
  }

  for (int i = 0; i < vec.size(); i++) std::cout << vec[i];

  std::cout << std::endl << min << std::endl << max << std::endl << sum << std::endl << prod << std::endl;

  return 0;
}