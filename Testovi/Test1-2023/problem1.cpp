#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

vector<int> fib(int n)
{
  if (n <= 0) throw runtime_error("Unos za n nije validan!");

  vector<int> rez;

  rez.push_back(1);
  if (n == 1) return rez;

  rez.push_back(1);
  if (n == 2) return rez;

  int p = 1;
  int t = 1;

  for (int i = 2; i < n; i++)
  {
    rez.push_back(p + t);
    t = rez[i];
    p = rez[i - 1];
  }

  return rez;
}

template <typename T, typename U>
T pronadji(const T& p, const T& k, U f)
{
  T it = p;

  while (it != k)
  {
    if (f(*it)) return it;
    ++it;
  }

  return k;
}

int main()
{
  int n = 0;

  if (!(cin >> n))
  {
    cout << "Unos mora biti broj!\n";
    return 0;
  }

  vector<int> vec;

  try
  {
    vec = fib(n);
  }
  catch (runtime_error err)
  {
    cout << err.what() << endl;
    return 0;
  }

  auto f = [](int x) { return x % 11 == 0; };
  auto el = pronadji(vec.begin(), vec.end(), f);

  if (el != vec.end())
    cout << *el << endl;
  else
    cout << "Nema elemenata djeljivih sa 11!\n";

  return 0;
}
