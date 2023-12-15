// Napisati program koji trazi unos decimalnog broja,
// te brise sve 0 iza zareza unesenog broja. Ukoliko
// su iza zareza sve nule program treba da izbrise i
// decimalnu tacku.
//
// Primjeri:
// Unesite broj: 5.41000
// 5.41
//
// Unesite broj: 5
// 5
//
// Unesite broj: 5.00000
// 5
//
// Unesite broj: 5000
// 5000
//
// Unesite broj: 5000.
// 5000

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  double n;

  std::cout << "Unesite broj: ";

  if (!(std::cin >> n))
  {
    std::cout << "Unos nije validan!\n";
    return 0;
  }

  std::string out;
  if (n == (int)n)
    out = std::to_string((int)n);
  else
  {
    out = std::to_string(n);
    int index_of_zero = -1;
    bool allow_count = true;
    for (int i = 0; i < out.size(); i++)
    {
      if (out[i] == '.')
      {
        if (allow_count)
          index_of_zero = i;
        allow_count = true;
      }
      else if (out[i] == '0')
      {
        if (allow_count)
          index_of_zero = i;
        allow_count = false;
      }
      else
      {
        index_of_zero = -1;
        allow_count = true;
      }
    }

    if (out[index_of_zero] == '.') index_of_zero--;

    if (index_of_zero > 0)
      out = out.substr(0, index_of_zero);
  }

  std::cout << out << '\n';

  return 0;
}
