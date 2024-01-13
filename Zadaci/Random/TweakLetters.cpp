#include <iostream>
#include <string>

std::string tweakLetters(std::string s, int arr[])
{
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] + arr[i] > 'z')
      s[i] += arr[i] - 'z' + 'a' - 1;
    else if (s[i] + arr[i] < 'a')
      s[i] += arr[i] + 'z' - 'a' + 1;
    else
      s[i] += arr[i];
  }

  return s;
}

int main(int argc, char* argv[])
{
  int arr[] = { 0, 1, -1, 0, -1 };
  std::cout << tweakLetters("apple", arr) << std::endl;

  return 0;
}
