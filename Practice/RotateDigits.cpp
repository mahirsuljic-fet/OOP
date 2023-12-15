#include <iostream>

int rotatedDigits(int n)
{
  int out = 0;
  bool valid = true;
  for (int i = 1; i <= n; i++)
  {
    valid = true;
    int t = i;
    int newN = 0;
    while (t > 0)
    {
      int dig = t % 10;

      if (!(dig == 2 || dig == 5 || dig == 6 || dig == 9))
      {
        valid = false;
        break;
      }

      switch (dig)
      {
      case 2: dig = 5; break;
      case 5: dig = 2; break;
      case 6: dig = 9; break;
      case 9: dig = 6; break;
      }

      newN = (newN + dig) * 10;
      t /= 10;
    }

    if (valid && newN / 10 != i) out++;
  }

  return out;
}

int main(int argc, char* argv[])
{
  int n{};
  std::cin >> n;
  std::cout << rotatedDigits(n) << '\n';

  return 0;
}
