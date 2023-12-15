#include <chrono>
#include <iostream>
#include <map>
#include <unordered_map>

int main(int argc, char* argv[])
{
  auto roll = []() { return rand() % 6 + 1; };

  std::map<std::string, int> map;
  std::unordered_map<std::string, int> umap;

  map["one"] = 1;
  map["two"] = 2;
  map["three"] = 3;
  map["four"] = 4;
  map["five"] = 5;
  map["six"] = 6;

  umap["one"] = 1;
  umap["two"] = 2;
  umap["three"] = 3;
  umap["four"] = 4;
  umap["five"] = 5;
  umap["six"] = 6;

  std::cout << "Map\n";
  for (auto& i : map) std::cout << i.first << " = " << i.second << '\n';

  std::cout << "\n\nUnodrered map\n";
  for (auto& i : umap) std::cout << i.first << " = " << i.second << '\n';

  return 0;
}
