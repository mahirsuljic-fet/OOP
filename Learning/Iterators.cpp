#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  map<string, int> stanice = {
    { "bht1", 8 },
    { "rtvtk", 15 }
  };

  stanice["tvt"] = 15;
  stanice["ftv"]++;

  for (auto it = stanice.begin(); it != stanice.end(); ++it)
    cout << it->first << ": " << it->second << endl;

  return 0;
}
