#include <iostream>
#include <list>

std::list<int> parni_neparni(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
  std::list<int> result;
  std::list<int> right;
  std::list<int> left;

  for (auto it = begin; it != end; ++it)
  {
    if (!(*it % 2))
      left.push_back(*it);
    else
      right.push_back(*it);
  }

  for (auto it = left.begin(); it != left.end(); ++it)
    result.push_back(*it);
  for (auto it = right.begin(); it != right.end(); ++it)
    result.push_back(*it);

  return result;
}

int main(int argc, char* argv[])
{
  std::list<int> nums { 15, 20, 25, -10, -75, 100, -255, 430, 200 };
  auto result = ::parni_neparni(nums.cbegin(), nums.cend());

  for (auto num : result)
    std::cout << num << ' ';
  std::cout << std::endl;

  return 0;
}
