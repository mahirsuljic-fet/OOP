#include <iostream>
#include <string>
#include <vector>

std::vector<int> sortNumsAscending(std::vector<int> arr)
{
  bool swapped = true;

  while (swapped)
  {
    swapped = false;
    for (int i = 0; i < arr.size() - 1; i++)
    {
      if (arr[i + 1] < arr[i])
      {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }
  }

  return arr;
}

int main(int argc, char* argv[])
{
  std::vector<int> arr = { 45, 98, 35, 65, 97, 21, 33 };

  for (auto n : arr) std::cout << n << " ";
  std::cout << std::endl;

  arr = sortNumsAscending(arr);

  for (auto n : arr) std::cout << n << " ";
  std::cout << std::endl;
  return 0;
}
