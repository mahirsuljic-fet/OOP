// Napisati program koji trazi od korisnika unos imena,
// a zatim na ekran ispisuje uokvireno ime sa praznim prostorom
// sirine 2 karaktera. 
//
// Primjer:
//
// Unesite ime: Mirza
// **********************
// **********************
// **                  **
// **                  **
// **  Pozdrav Mirza!  **
// **                  **
// **                  **
// **********************
// **********************
//

#include <iostream>
#include <string>

int main (int argc, char *argv[])
{
  std::string pre = "Pozdrav ";
  std::string s;
  std::string post = "!";

  std::cout << "Unesite svoje ime: ";
  std::cin >> s;

  int len = pre.size() + s.size() + post.size();
  const int border = 1;
  const int padding = 1;

  for (int i = 0; i < 2*(border + padding) + 1; i++)
  {
    for (int j = 0; j < len + 2*(border + padding); j++)
    {
      if (i < border || i > border + 2*padding ||
        j < border || j > len + border + 2*padding - 1)
        std::cout << "*";
      else if (i == border + padding && j == border + padding)
      {
        std::cout << pre << s << post;
        j += len - 1;
      }
      else std::cout << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}
