#include <functional>
#include <iostream>
#include <list>

std::list<int> partition(std::list<int>::const_iterator begin, std::list<int>::const_iterator end, std::function<bool(int)> predicate)
{
  std::list<int> result;
  std::list<int> right;
  std::list<int> left;

  try
  {
    for (auto it = begin; it != end; ++it)
    {
      if (predicate(*it))
        left.push_back(*it);
      else
        right.push_back(*it);
    }
  }
  catch (...)
  {
    std::cout << "Exception caught!\n";
    for (auto it = begin; it != end; ++it)
      result.push_back(*it);

    return result;
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
  auto result_err = ::partition(nums.cbegin(), nums.cend(), [](int num) { if (num > 400) throw 5; return num > 0; });

  for (auto num : result_err)
    std::cout << num << ' ';
  std::cout << std::endl;

  return 0;
}
