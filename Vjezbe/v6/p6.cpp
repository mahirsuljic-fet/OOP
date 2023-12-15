#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

int main(void)
{
  // std::terminate();  // funkcija koja terminira izvrsenje programa
  // std::exception     // generalni tip exceptiona od kojeg svi ostali nasljedjuju (invalid_argument, out_of_range, itd.)

  std::vector<std::string> vek { "dva", "elementa" };
  try
  {
    auto elem = vek.at(2);
  }
  catch (std::invalid_argument& err)
  {
    std::cout << "Invalid argument caught: " << err.what() << std::endl;
  }
  // catch (std::out_of_range& err)
  catch (std::exception& err)
  {
    std::cout << "Out of range caught: " << err.what() << std::endl;
  }

  return 0;
}
