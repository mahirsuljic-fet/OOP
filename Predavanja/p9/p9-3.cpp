#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char* argv[])
{
  std::list<int> l = { 2, 3, 5 };

  l.push_front(10);

  auto it = std::begin(l);

  // it + c nije dozvoljeno jer je iterator bidirekcioni
  std::cout << *it << " " << *(++it) << " " << *(--it) << std::endl;

  // std::sort() trazi random access iteratore, tako da se list ne moze sorirat preko njega

  l.sort();
  for (const auto& e : l)
    std::cout << e << " ";
  std::cout << std::endl;

  return 0;
}
