#include <iostream>

int main(int argc, char* argv[])
{
  std::string s = "V5";
  auto& a = s;

  a = "Ref?";
  a = a + ": Hello";

  std::cout << s << std::endl;

  return 0;
}
