#include <functional>
#include <iostream>
#include <list>

std::list<int> partition(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, std::function<bool(int)> predicate)
{
  std::list<int> result;
  std::list<int> right;
  std::list<int> left;

  for (auto it = begin; it != end; ++it)
  {
    if (predicate(*it))
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
  auto result1 = ::partition(nums.cbegin(), nums.cend(), [](int num) { return !(num % 2); });
  auto result2 = ::partition(nums.cbegin(), nums.cend(), [](int num) { return num > 0; });
  auto result3 = ::partition(nums.cbegin(), nums.cend(), [](int num) { return !(num % 10); });
  auto result4 = ::partition(nums.cbegin(), nums.cend(), [](int num) { return std::abs(num) > 99; });

  std::cout << "!(num % 2)   :\t";
  for (auto num : result1)
    std::cout << num << ' ';
  std::cout << std::endl;

  std::cout << "num > 0      :\t";
  for (auto num : result2)
    std::cout << num << ' ';
  std::cout << std::endl;

  std::cout << "!(num % 10)  :\t";
  for (auto num : result3)
    std::cout << num << ' ';
  std::cout << std::endl;

  std::cout << "abs(num) > 99:\t";
  for (auto num : result4)
    std::cout << num << ' ';
  std::cout << std::endl;

  return 0;
}
