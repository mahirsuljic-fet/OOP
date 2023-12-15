// Napisati funkciju copy_if koja uzima 4 parametra:
// 1. pocetak sekvence
// 2. kraj sekvence
// 3. destinacija
// 4. predicate funkcija
//
// copy_if treba da kopira elemente koji zadovoljavaju predicate funkciju
// ulazne sekvence na destinaciju. Funkcija treba da radi za razlicite tipove
// kontejnera.

#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

template <typename T, typename U, typename V>
void copy_if(T begin, T end, U dest, V predicate)
{
  while (begin++ != end)
    if (predicate(*begin))
      *dest = *begin;
}

int main(int argc, char* argv[])
{
  std::vector<int> vint { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::vector<int> parni;

  // pozvati copy_if
  ::copy_if(vint.begin(), vint.end(), std::back_inserter(parni), [](int n) { return !(n % 2); });

  std::cout << "Parni: " << std::endl;
  for (int n : parni)
  {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  std::list<int> lint { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::list<int> neparni;

  // pozvati copy_if
  ::copy_if(lint.begin(), lint.end(), std::back_inserter(neparni), [](int n) { return n % 2; });

  std::cout << "Neparni: " << std::endl;
  for (int n : neparni)
  {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  std::list<std::string> lstr { "hello", "auto", "world", "ant", "all", "exercise" };
  std::list<std::string> stringovi_sa_a;

  // pozvati copy_if
  ::copy_if(lstr.begin(), lstr.end(), std::front_inserter(stringovi_sa_a), [](std::string n) { return n.size() > 0 ? n[0] == 'a' : false; });

  std::cout << "Stringovi koji pocinju sa a u obrnutom redoslijedu: " << std::endl;
  for (std::string s : stringovi_sa_a)
  {
    std::cout << s << ' ';
  }
  std::cout << std::endl;

  return 0;
}
