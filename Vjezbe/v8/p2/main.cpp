#include "Cplx.hpp"
#include <iostream>

int main(void)
{
  vjezbe10::Cplx cp1(1, 1), cp2(2, -3);

  std::cout << "Cp1: " << cp1.toString() << std::endl;
  std::cout << "Cp2: " << cp2.toString() << std::endl;

  std::cout << "Module and angle: " << std::endl;
  std::cout << cp1.modulus() << std::endl;
  std::cout << cp1.angle().getValue() << std::endl;

  std::cout << "Construct from module and radian: " << std::endl;

  double mod = 7;
  vjezbe10::Radian r { 3.14 };
  vjezbe10::Cplx cp3(mod, r);
  std::cout << cp3.toString() << std::endl;

  std::cout << "Add operator: " << std::endl;

  auto cp4 = cp1.add(cp2);
  std::cout << "Cp1: " << cp1.toString() << std::endl;
  std::cout << "Cp2: " << cp2.toString() << std::endl;
  std::cout << "Cp4: " << cp4.toString() << std::endl;

  std::cout << "Append operator: " << std::endl;

  cp4.append(cp1).append(cp3);

  std::cout << "Cp1: " << cp1.toString() << std::endl;
  std::cout << "Cp3: " << cp3.toString() << std::endl;
  std::cout << "Cp4: " << cp4.toString() << std::endl;

  std::cout << "Make negative: " << std::endl;

  auto cp3Neg = cp3.makeNegative();
  std::cout << "Cp3: " << cp3Neg.toString() << std::endl;

  // Ne moze se kompajlirati:
  // vjezbe10::Radian rad = 10.;

  return 0;
}
