#include <iostream>
#include <string>

template <typename T, typename U>
bool jednako(const T& begin_first, const T& end_first, const U& begin_second)
{
  auto it1 = begin_first;
  auto it2 = begin_second;

  while (it1 != end_first)
  {
    if (*it1 != *it2)
      return false;

    ++it1;
    ++it2;
  }

  return true;
}

int main(int argc, char* argv[])
{
  std::string s;

  std::cout << "palindrom\n";
  while (std::cin >> s)
  {
    if (jednako(s.begin(), s.end(), s.rbegin()))
      std::cout << s << ": Palindrom\n";
    else
      break;
  }

  return 0;
}
