// Mahir Suljic - OOP Zadaca 2023. - Zadatak 6

#include <iostream>
#include <string>

int main()
{
  long a, b;
  char op;
  bool success = false;

  std::string s_a = "";
  std::string s_b = "";
  std::string s_op = "";

  while (!success)
  {
    std::cout << "Input: ";
    std::cin >> s_a >> s_op >> s_b;

    success = true;

    // ako je prvi karakter '-' preskoci provjeru prvog karaktera
    for (int i = s_a[0] == '-' ? 1 : 0; i < s_a.size(); i++)
    {
      if (s_a[i] < '0' || s_a[i] > '9')
      {
        std::cout << s_a << " is not a valid input!\n";
        success = false;
        break;
      }
    }

    if (s_op.size() > 1 || (s_op[0] != '+' && s_op[0] != '-' && s_op[0] != '*' && s_op[0] != '/' && s_op[0] != '%' && s_op[0] != '^'))
    {
      std::cout << s_op << " is not a valid input!\n";
      success = false;
    }

    for (int i = s_b[0] == '-' ? 1 : 0; i < s_b.size(); i++)
    {
      if (s_b[i] < '0' || s_b[i] > '9')
      {
        std::cout << s_b << " is not a valid input!\n";
        success = false;
        break;
      }
    }

    std::cout << std::endl;
  }

  a = std::stol(s_a);
  b = std::stol(s_b);
  op = s_op[0];

  switch (op)
  {
  case '+':
    std::cout << a + b << std::endl;
    break;
  case '-':
    std::cout << a - b << std::endl;
    break;
  case '*':
    std::cout << a * b << std::endl;
    break;
  case '/':
    if (b == 0)
    {
      std::cout << "Division by zero is undefined!\n";
      break;
    }
    std::cout << (double)a / b << std::endl;
    break;
  case '%':
    std::cout << a % b << std::endl;
    break;
  case '^':
  {
    if (b == 0) std::cout << "1" << std::endl;

    long res = 1;
    for (int i = 0; i < (b > 0 ? b : -b); i++)
      res *= a;

    std::cout << (b > 0 ? res : 1.0 / res) << std::endl;
  }
  break;
  }

  return 0;
}