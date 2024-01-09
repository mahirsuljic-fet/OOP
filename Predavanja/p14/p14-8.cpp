#include <iostream>
#include <vector>

template <typename T, typename U>
struct par
{
    T prvi;
    U drugi;
};

// typedef par<int, double> foobar; // OK
// typedef par<int, M> foobar; // greska
// typedef par foobar; // greska

// ne moze genericki typedef ali moze sa using
template <typename T, typename U>
using foobar = par<T, U>;

template <typename T>
using iter = typename std::vector<T>::iterator;

int main(int argc, char* argv[])
{

  return 0;
}
