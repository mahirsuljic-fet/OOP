#include <functional>
#include <iostream>

void foo(std::function<void()>& f)
{
  // int n = 10;

  int* n_ptr = new int { 10 };

  // std::cout << "|" << *n << "|\n";

  f = [n_ptr]() {
    std::cout << *n_ptr << std::endl;
    delete n_ptr;
  };
}

// g++ -std=c++14 -fsanitize=address p1.cpp -o p1
// ovo moze pomoci i kad imamo segmentation fault, dodat i -g

int main(int argc, char* argv[])
{
  std::function<void()> f;
  foo(f);
  f();
  return 0;
}
