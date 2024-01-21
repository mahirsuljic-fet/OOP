#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  int i = 1;

  // =======================
  // |      REFERENCE      |
  // =======================

  int& i_lr1 = i;
  const int& i_clr1 = i;

  // int& i_lr2 = 2;
  const int& i_clr2 = 3;

  int&& i_rr1 = 4;
  const int&& i_crr1 = 5;

  // int&& i_rr2 = i;
  // const int&& i_crr2 = i;

  int& i_lr3 = i_rr1;
  // int& i_lr4 = i_crr1;

  const int& i_clr3 = i_rr1;
  const int& i_clr4 = i_crr1;

  // =======================
  // |        MOVE         |
  // =======================

  int& i_l = i;
  const int& i_cl = 0;
  int&& i_r = 0;
  const int&& i_cr = 0;

  std::cout << std::is_same<decltype(std::move(i)), int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_l)), int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_cl)), const int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_r)), int&&>::value << std::endl
            << std::is_same<decltype(std::move(i_cr)), const int&&>::value << std::endl;

  return 0;
}
