#include <chrono>
#include <iostream>

constexpr unsigned short numOfIterations = 100;
void timedFunction()
{
}

int main(int argc, char* argv[])
{
  std::chrono::duration<double> t(0);
  unsigned long long avg = 0;

  for (int i = 0; i < numOfIterations; i++)
  {
    auto tp1 = std::chrono::high_resolution_clock::now();

    timedFunction();

    auto tp2 = std::chrono::high_resolution_clock::now();
    t = tp2 - tp1;

    avg += std::chrono::duration_cast<std::chrono::microseconds>(t).count();
  }

  avg /= numOfIterations;

  std::cout << avg << "us\n";

  return 0;
}
