#include <chrono>
#include <iostream>
#include <list>

int main(int argc, char* argv[])
{
  auto roll = []() { return rand() % 6 + 1; };

  std::list<int> list;

  list.push_back(roll());
  const int* pAddressOfOriginal = &(*list.begin());

  std::chrono::duration<double> durInsertTime(0);

  do
  {
    const int* pAddressOfItemZero = &(*list.begin());

    std::cout << "Contains " << list.size() << " elements, took " << std::chrono::duration_cast<std::chrono::microseconds>(durInsertTime).count() << "us\n";

    for (const auto& i : list)
    {
      const int* pAddressOfItemX = &i;
      int pItemOffset = pAddressOfItemX - pAddressOfItemZero;
      int pItemOffsetOriginal = pAddressOfItemX - pAddressOfOriginal;

      std::cout << "Offset from original: " << pItemOffsetOriginal << "   \tOffset from zero: " << pItemOffset << "\tContent: " << i << '\n';
    }

    auto tp1 = std::chrono::high_resolution_clock::now();
    list.push_back(roll());
    auto tp2 = std::chrono::high_resolution_clock::now();
    durInsertTime = tp2 - tp1;
  }
  while (getc(stdin));

  return 0;
}
