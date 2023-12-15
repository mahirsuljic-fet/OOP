#include <iostream>
#include <ostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void foo(int& a)
{
  a = 25;
}

int main(int argc, char* argv[])
{
  int b = 2;
  int& a = b;

  cout << a << " - " << b << endl;

  foo(b);

  cout << a << " - " << b << endl;

  return 0;
}
