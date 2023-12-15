#include <chrono>
#include <iostream>
#include <unordered_set>

int main(int argc, char* argv[])
{
  auto roll = []() { return rand() % 6 + 1; };

  std::unordered_set<int> uset;

  uset.insert(roll());
  const int* pAddressOfOriginal = &(*uset.begin());

  std::chrono::duration<double> durInsertTime(0);

  do
  {
    const int* pAddressOfItemZero = &(*uset.begin());

    std::cout << "Contains " << uset.size() << " elements, took " << std::chrono::duration_cast<std::chrono::microseconds>(durInsertTime).count() << "us\n";

    for (const auto& i : uset)
    {
      const int* pAddressOfItemX = &i;
      int pItemOffset = pAddressOfItemX - pAddressOfItemZero;
      int pItemOffsetOriginal = pAddressOfItemX - pAddressOfOriginal;

      std::cout << "Offset from original: " << pItemOffsetOriginal << "   \tOffset from zero: " << pItemOffset << "\tContent: " << i << '\n';
    }

    auto tp1 = std::chrono::high_resolution_clock::now();
    uset.insert(roll());
    auto tp2 = std::chrono::high_resolution_clock::now();
    durInsertTime = tp2 - tp1;
  }
  while (getc(stdin));

  return 0;
}
