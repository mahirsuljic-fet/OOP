#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/
long long countHomogenous(std::string s)
{
  long long count = 0;
  int subcount = 1;
  const char* arr = s.c_str();
  char lastChar = '\0';

  for (int i = 0; i < s.size(); i++)
  {
    if (arr[i] == lastChar)
    {
      subcount++;
      count += subcount;
    }
    else
    {
      lastChar = arr[i];
      subcount = 1;
      count++;
    }
  }

  return count % (10L * 10L * 10L * 10L * 10L * 10L * 10L * 10L * 10L + 7L); // 10^9 + 7
}

int main(int argc, char* argv[])
{
  std::string s = "abbcccaa";
  std::cout << "Analysing string \"" << s << "\"...\n\nFound " << countHomogenous(s) << " homogenous substrings in string \"" << s << "\"" << std::endl;

  return 0;
}