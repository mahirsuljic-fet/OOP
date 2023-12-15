// Napisati funkciju filter koja treba da isfiltrira proslijedjeni
// vektor na nacin da kopira elemente proslijedjenog vektora koji
// zadovoljavaju dati predicate. Ukoliko je proslijedjena nevalidna
// predicate funkcija, potrebno je baciti iznimku tipa:
//    std::logic_error
//
// Nakon toga, dodati jos jednu (overloaded) funkciju filter koja
// uzima vektor i string te kopira sve stringove koji odgovaraju
// datom argumentu u rezultujuci vektor.

#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using vec_str_it = std::vector<std::string>::iterator;

std::vector<std::string> filter(vec_str_it begin, vec_str_it end,
  std::function<bool(const std::string&)> predicate)
{
  if (!predicate) throw std::logic_error("Predikat nije validan!");

  std::vector<std::string> result;

  for (auto it = begin; it != end; ++it)
    if (predicate(*it))
      result.push_back(*it);

  return result;
}

std::vector<std::string> filter(std::vector<std::string> vec, std::string str)
{
  std::vector<std::string> result;

  for (auto el : vec)
    if (el == str)
      result.push_back(el);

  return result;
}

/*
 * postoji funkcija std::advance(it, num) i koristi se da
 * iterator pomjerimo nekliko mijesta
 */

int main(int argc, char* argv[])
{
  std::vector<std::string> vec;
  std::string s;

  std::cout << "Unesite rijeci: " << std::endl;
  while (std::cin >> s)
  {
    vec.push_back(s);
  }

  auto filtered = filter(vec.begin(), vec.end(), [](const std::string& s) {
    return s.size() > 5;
  });

  std::cout << "Result: " << std::endl;
  for (auto&& el : filtered)
    std::cout << el << std::endl;

  return 0;
}
