#include <iostream>
#include <string>
#include <vector>

std::vector<int> noOdds(std::vector<int> arr)
{
	for (int i=0; i<arr.size(); i++) if(arr[i] % 2) arr.erase(arr.begin() + i--);
  return arr;
}

int main (int argc, char *argv[])
{

  return 0;
}
