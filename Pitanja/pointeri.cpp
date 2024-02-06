#include <iostream>

// Da li je ovo definisano ponasanje?
//
// Ako jest, i ako su x i y isti, zasto *x nije 29?
// x i y su lokalne varijable, ali zar ne pristupaju
// istoj adresi pa time i istoj vrijednosti?
// Kako je moguce da je *y 29, a *x 30?
void foo(double* x, double* y)
{
  *x = *x * --(*y);
}

int main(int argc, char* argv[])
{
  double n = 30;

  foo(&n, &n);

  std::cout << n << std::endl;

  return 0;
}
