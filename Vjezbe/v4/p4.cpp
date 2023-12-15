// Napisati program koji trazi od korisnika unos brojeva.
// Unos se zavrsava kada korisnik unese "EOF" karakter.
// Program treba prvo da ispise sve unesene brojeve,
// te nakon toga da ispise samo one brojeve koji zadovoljavaju
// sljedeci uslov:  v[n-1] > v[n] < v[n+1]
//

#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<double> nums;
  double n {};

  do
  {
    std::cout << "Unesite broj: ";
    std::cin >> n;

    if (std::cin) nums.push_back(n);
  }
  while (std::cin);

  std::cout << "\n\nSvi brojevi: ";
  for (double n : nums) std::cout << n << ' ';

  std::cout << "\nBrojevi sa uslovom: ";
  for (int i = 1; i < nums.size() - 1; i++)
    if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
      std::cout << nums[i] << ' ';
  std::cout << std::endl;

  return 0;
}
