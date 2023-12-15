#include "../../usefulminifuncs.cpp"
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<int> v = { 5000, 10, 0, 1 };

  auto it1 = std::end(v);
  auto bi = std::back_inserter(v);

  *bi = 5000;
  print_container(v);

  ++bi; // nista ne radi, boli njega briga

  *bi = 10000;
  print_container(v);

  auto ii = std::inserter(v, std::begin(v) + 3); // insertuje prije v[3]

  *ii = -18;
  print_container(v);

  ++ii; // nista ne radi

  *ii = 20;
  print_container(v);

  // auto fi = std::front_inserter(v);
  // *fi = -5000; ne valja jer vector ne podrzaje front_inserter

  v.erase(v.begin() + 3); // brise v[3]
  print_container(v);

  v.erase(std::begin(v) + 3, v.end()); // [ v.begin(), v.end() )
  print_container(v);

  auto it = std::begin(v);
  v.push_back(-4);
  // *it; nedefinirano ponasanje, mozda se premjestio

  it = v.begin();
  *it; // validno

  return 0;
}
