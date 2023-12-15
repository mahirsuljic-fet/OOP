// Napisati funkciju filter koja treba da isfiltrira proslijedjeni
// vektor na nacin da kopira elemente proslijedjenog vektora koji
// zadovoljavaju dati predicate. Ukoliko je proslijedjena nevalidna
// predicate funkcija, potrebno je baciti iznimku tipa:
//    std::logic_error
//
// Nakon toga, dodati jos jednu (overloaded) funkciju filter koja
// uzima vektor i string te kopira sve stringove koji odgovaraju
// datom argumentu u rezultujuci vektor.

#include "../../usefulminifuncs.cpp"
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> filter(const std::vector<std::string>& v,
  std::function<bool(const std::string&)> predicate)
{
  if (!predicate)
    throw std::logic_error { "Predikat nije validan!" };

  std::vector<std::string> rez;

  for (auto& s : v) // s je const jer je v const
    if (predicate(s))
      rez.push_back(s);

  return rez;
}

int main(int argc, char* argv[])
{
  std::vector<std::string> vec;
  std::string s;

  std::cout << "Unesite rijeci: " << std::endl;
  while (std::cin >> s)
  {
    vec.push_back(s);
  }

  try
  {
    auto filtered = filter(vec, [](const std::string& s) {
      return s.size() > 5;
    });

    std::cout << "\n";
    print_container(filtered, "\n");
  }
  catch (std::logic_error err)
  {
    std::cout << err.what() << std::endl;
  }
  return 0;
}
