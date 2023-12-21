#include <iostream>

void foo(int&);
void bar(const int& r)
{
  r + 1;
}

int main(int argc, char* argv[])
{
  const int& a = 5;
  int b;

  foo(b);
  bar(b);

  // foo(5); // error
  bar(5);

  return 0;
}
