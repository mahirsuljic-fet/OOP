#include <algorithm>
#include <iostream>

// void bar(std::string s) { std::cout << "copy" << std::endl;}
void bar(std::string& s) { std::cout << "ref" << std::endl; }
void bar(const std::string& s) { std::cout << "const ref" << std::endl; }
void bar(std::string&& s) { std::cout << "rvalue ref" << std::endl; }

int main(int argc, char* argv[])
{
  const std::string text { "text" };

  bar(text);
  bar(std::string { "text" });
  bar("text"); // trazi bar(const char*), posto nema isto je kao i prethodni poziv

  std::string text1 { "text" };
  bar(text1);

  bar(std::move(text));
  // move dodaje && na tip varijable
  // tj pokusa pretvorit u rvalue
  // ali moze da ne uspije
  // move zapravo nista ne move-a

  return 0;
}
