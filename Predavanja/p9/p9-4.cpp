#include <iostream>
#include <iterator>
#include <map>
#include <string>

int main(int argc, char* argv[])
{
  std::map<int, double> m_id { { 2, 3.3 }, { 0, -4.1 }, { 8, 2.2 }, { 0, 4 } }; // za 0 je -4.1, jer se prvi definirao
  std::cout << m_id[0] << '\n';

  std::map<std::string, std::string> be { { "stolica", "chair" }, { "stol", "desk" } };
  std::cout << be["stol"] << std::endl;

  be["stol"] = "table";
  std::cout << be["stol"] << std::endl;

  be["knjiga"]; // ako nema dodat ce novi element
  std::cout << be["knjiga"] << std::endl;

  be["knjiga"] = "book";
  std::cout << be["knjiga"] << std::endl;

  auto it = std::begin(be);
  std::cout << it->first << " => " << it->second << std::endl;

  // kljucevi su konstante i ne mogu se mijenjati preko iteratora

  auto it1 = be.find("kabl");
  if (it1 != be.end())
    std::cout << it1->second << std::endl;
  else
    std::cout << "NEMA!\n";

  be["kabl"] = "cable";

  if (it1 != be.end())
    std::cout << it1->second << std::endl;
  else
    std::cout << "NEMA!\n";

  it1 = be.find("kabl");
  if (it1 != be.end())
    std::cout << it1->second << std::endl;
  else
    std::cout << "NEMA!\n";

  be.erase("kabl");

  it1 = be.find("kabl");
  if (it1 != be.end())
    std::cout << it1->second << std::endl;
  else
    std::cout << "NEMA!\n";

  /*
   * ako se izbrise element u listi ili mapi na koji neki iterator
   * pokazuje, tada je taj iterator invalidan
   * ako se izbrise element u listi ili mapi na koji neki iterator
   * NE pokazuje, taj iterator ostaje validan
   */

  return 0;
}
