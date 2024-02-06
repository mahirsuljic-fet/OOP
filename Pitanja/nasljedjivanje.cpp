#include <iostream>
#include <vector>

// Zasto u primjeru ispod struktura Bar ne moze
// koristiti vec, iako je specificirano da je
// Foo, pa time i vec, napravljen sa <T>?

template <typename T>
struct Foo
{
    std::vector<T> vec;
};

template <typename T>
struct Bar : Foo<T>
{
    void tar(T value)
    {
      vec.push_back(value);
    }
};

int main(int argc, char* argv[])
{

  return 0;
}
