#include "./usefulminifuncs.cpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<int> v = random_vector_int(10);
  std::list<int> l = random_list_int(10);
  std::map<std::string, int> m = ordered_map_string_int(10);
  int* arr_d = random_array_int(5, 1, 10);
  int arr_s[5] = { 1, 2, 3, 4, 5 };

  print_container(v);
  print_container(l);
  print_container(m);
  print_container(arr_d, 5);
  print_container(arr_d, arr_d + 5);
  print_container(arr_s, 5);
  print_container(arr_s, arr_s + 5);
  print_container(std::begin(arr_s), std::end(arr_s));

  return 0;
}
