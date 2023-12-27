// Napisati funkciju copy_if koja uzima 4 parametra:
// 1. pocetak sekvence
// 2. kraj sekvence
// 3. destinacija
// 4. predicate funkcija
//
// copy_if treba da kopira elemente koji zadovoljavaju predicate funkciju
// ulazne sekvence na destinaciju. Funkcija treba da radi za razlicite tipove
// kontejnera.

#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

template <typename T, typename U, typename V>
void copy_if(const T& begin, const T& end, U dest, const V& predicate)
{
  T it = begin;

  while (it != end)
  {
    if (predicate(*it))
      *dest = *it;
    ++it;
  }
}

int main(int argc, char* argv[])
{
  std::vector<int> vint { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::vector<int> parni;

  auto f_parni = [](int n) { return n % 2 == 0; };
  auto f_neparni = [](int n) { return n % 2; };
  auto f_str_sa_a = [](std::string s) { return s.find('a') != std::string::npos; };

  // pozvati copy_if
  copy_if(vint.cbegin(), vint.cend(), std::back_inserter(parni), f_parni);

  std::cout
    << "Parni: " << std::endl;
  for (int n : parni)
  {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  std::list<int> lint { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::list<int> neparni;

  // pozvati copy_if
  copy_if(lint.cbegin(), lint.cend(), std::back_inserter(neparni), f_neparni);

  std::cout << "Neparni: " << std::endl;
  for (int n : neparni)
  {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  std::list<std::string> lstr { "hello", "auto", "world", "ant", "all", "exercise" };
  std::list<std::string> stringovi_sa_a;

  // pozvati copy_if
  copy_if(lstr.cbegin(), lstr.cend(), std::front_inserter(stringovi_sa_a), f_str_sa_a);

  std::cout << "Stringovi koji pocinju sa a u obrnutom redoslijedu: " << std::endl;
  for (std::string n : stringovi_sa_a)
  {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  return 0;
}
