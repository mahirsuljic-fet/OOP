#include <chrono>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
  auto roll = []() { return rand() % 6 + 1; };

  std::vector<int> vec;

  vec.push_back(roll());
  const int* pAddressOfOriginal = &(*vec.begin());

  std::chrono::duration<double> durInsertTime(0);

  do
  {
    const int* pAddressOfItemZero = &(*vec.begin());

    std::cout << "Contains " << vec.size() << " elements, took " << std::chrono::duration_cast<std::chrono::microseconds>(durInsertTime).count() << "us\n";

    for (const auto& i : vec)
    {
      const int* pAddressOfItemX = &i;
      int pItemOffset = pAddressOfItemX - pAddressOfItemZero;
      int pItemOffsetOriginal = pAddressOfItemX - pAddressOfOriginal;

      std::cout << "Offset from original: " << pItemOffsetOriginal << "   \tOffset from zero: " << pItemOffset << "\tContent: " << i << '\n';
    }

    auto tp1 = std::chrono::high_resolution_clock::now();
    vec.push_back(roll());
    auto tp2 = std::chrono::high_resolution_clock::now();
    durInsertTime = tp2 - tp1;
  }
  while (getc(stdin));

  return 0;
}
