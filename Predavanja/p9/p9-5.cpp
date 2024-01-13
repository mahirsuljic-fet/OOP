#include <iostream>
#include <string>

template <typename T, typename U>
auto tajna_zivota(T a, U b)
{
  return a + b;
}

struct Student
{
    std::string ime;
    std::string prezime;
};

int main(int argc, char* argv[])
{
  auto a = tajna_zivota<int>(2, 2); // kompajler pravi novu funkciju
  auto b = tajna_zivota<int>(2, 3); // kompajler ne pravi novu funkciju nego koristi prethodno napravljenu
  auto c = tajna_zivota<double>(2.2, 2.3); // kompajler pravi novu funkciju
  auto d = tajna_zivota(2.7, 4.4);
  // auto t = tajna_zivota<Student>(Student { "foo", "bar" }, Student { "foo", "bar" }); invalidno jer nije definisano sabiranje sa Student
  auto m = tajna_zivota<int, double>(5, 10.4);
  auto n = tajna_zivota(2, 5.5);

  return 0;
}
