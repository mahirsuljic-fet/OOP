#include <iostream>

template <typename T>
void printLists(const T& list)
{
  list.print();
  std::cout << "===============" << std::endl;
}

template <typename T, typename... U>
void printLists(const T& list, const U&... others)
{
  printLists(list);
  printLists(others...);
}
