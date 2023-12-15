#include <iostream>
#include <ostream>
#include <vector>

typedef std::vector<double> kontejner;

void ispisSadrzajaKontejnera(const kontejner& k)
{
  // for (auto i = 0; i < k.size(); i++) std::cout << k[i] << " ";
  for (const auto& element : k) std::cout << element << " ";
}

auto unosSadrzajaKontejnera(kontejner& k)
{
}

int main(int argc, char* argv[])
{
  kontejner v { 5, 8, 3, 23, 101, 18 };

  ispisSadrzajaKontejnera(v);
  std::cout << std::endl;

  return 0;
}
