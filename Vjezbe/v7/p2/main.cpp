#include <iostream>
#include "operators.hpp"
#include "helpers.hpp"

int main(void)
{
  vjezbe08::Cplx c1, c2, c3;
  c1.re = 5.; c1.im = -2.;
  c2.re = 3.; c2.im = 6.;
  c3.re = 9.; c3.im = 0.;

  std::cout << "c1=";
  vjezbe08::print(c1);
  std::cout << std::endl;

  std::cout << "c2=";
  vjezbe08::print(c2);
  std::cout << std::endl;

  std::cout << "c3=";
  vjezbe08::print(c3);
  std::cout << std::endl;

  // Ispis:
  // c1=(5-2i)
  // c2=(3+6i)
  // c3=(9)

  // auto c4 = vjezbe08::add(c1, c2);
  // vjezbe08::print(c1);
  // std::cout << " + ";
  // vjezbe08::print(c2);
  // std::cout << " = ";
  // vjezbe08::print(c4);
  // std::cout << std::endl;

  // Ispis:
  // (5-2i) + (3+6i) = (8+4i)

  // auto c5 = vjezbe08::sub(c4, c3);
  // vjezbe08::print(c4);
  // std::cout << " - ";
  // vjezbe08::print(c3);
  // std::cout << " = ";
  // vjezbe08::print(c5);
  // std::cout << std::endl;

  // Ispis:
  // (8+4i) - (9) = (-1+4i)

  // auto c6 = vjezbe08::mul(c5, c4);
  // vjezbe08::print(c5);
  // std::cout << " * ";
  // vjezbe08::print(c4);
  // std::cout << " = ";
  // vjezbe08::print(c6);
  // std::cout << std::endl;

  // Ispis:
  // (-1+4i) * (8+4i) = (-24+28i)
 
  // std::cout << "c3=";
  // vjezbe08::print(c3);
  // std::cout << std::endl;
  //
  // vjezbe08::append(c3, c5);
  // vjezbe08::append(c3, c2);
  // 
  // std::cout << "c3=";
  // vjezbe08::print(c3);
  // std::cout << std::endl;
  
  // Ispis:
  // c3=(9)
  // c3=(11+10i)
  return 0;
}
