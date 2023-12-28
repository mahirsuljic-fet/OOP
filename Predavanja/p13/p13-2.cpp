#include <iostream>

int main(int argc, char* argv[])
{
  int a = 5;
  int& b { a };

  // int& c { 5 }; // error jer je 5 rvalue, a int& se moze vezati samo za lvalue
  const int& c { 5 };
  // c = 6; // error jer je c const, ne mozemo mijenjat vrijednost

  // pomocu rvlaue reference mozemo imati referencu na rvalue (npr. privremeni objekat)
  // i mozemo i mijenjat podatke koje se nalaze na referenciranoj lokaciji
  int&& r { 5 };
  r = 6;
  ++r;

  // int&& r1 = a; // error jer je a lvalue (npr. trajni objekat)
  // int&& r1 = ++a; // error jer je ++a lvalue, vraca a
  int&& r1 = a++; // r1 se veze za 5, a u varijablu a se pise 6, jer a++ vraca rvalue

  return 0;
}
