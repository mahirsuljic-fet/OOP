#include <iostream>
#include <iterator>
#include <string>

using std::cout, std::cin, std::endl;

template <typename input_it, typename output_it, typename lambda>
void copy_if(input_it __od, input_it __do, output_it __prema, lambda __op)
{
  for (; __od != __do; ++__od)
    if (__op(*__od))
      *__prema = *__od;
}

int main()
{
  std::ostream_iterator<std::string> cout_it(cout, "\n");

  *cout_it = "Unesite brojeve (unesite bilo koje slovo za prekid sekvence): ";

  copy_if(
    std::istream_iterator<int>(cin),
    std::istream_iterator<int>(),
    std::ostream_iterator<int>(cout, " "),
    [](int a) {
      return a > 5;
    });

  cout << endl;

  return 0;
}
