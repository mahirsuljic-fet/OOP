#include <iostream>

//=======================================================================================//
//                                     PITANJE 1                                         //
//=======================================================================================//

// sta je zapravo typename? zasto se u template moze koristiti class?

template <typename T>
void func_t(T x)
{
  std::cout << x << std::endl;
}

// isto kao i sljedece?

template <class T>
void func_c(T x)
{
  std::cout << x << std::endl;
}

int main(int argc, char* argv[])
{
  int x = 2;

  func_t(x);
  func_c(x);

  return 0;
}
