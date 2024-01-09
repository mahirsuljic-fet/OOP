#include <iostream>

template <typename T, typename U>
struct par
{
    T prvi;
    U drugi;

    // bool operator==(const par<T, U>& d) const
    // {
    //   return prvi == d.prvi && drugi == d.drugi;
    // }
};

template <typename T, typename U>
bool operator==(const par<T, U> a, const par<T, U>& b);

template <typename A, typename B>
par<A, B> kreirajPar(A a, B b)
{
  return par<A, B> { a, b };
}

int main(int argc, char* argv[])
{
  auto a = kreirajPar(5, 'c');
  auto b = kreirajPar(42, 'c');

  a = b;
  std::cout << (a == b) << std::endl;

  return 0;
}
