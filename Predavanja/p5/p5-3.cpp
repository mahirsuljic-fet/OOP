#include <iostream>
#include <string>
#include <vector>

// koristit cemo i list i map containere

// vector<double>(50,3.3) - 50 elemenata 3.3

int main (int argc, char *argv[])
{
  using std::string;
  using std::vector;
  using std::cout;
  using std::endl;
  using std::cin;

  vector<double> arr;
  double n = -1;
  double sum = 0;
  int c = 0;

  cout << "Unesi broj: ";
  cin >> n;

  while(n != 0)
  {
    arr.push_back(n);
    sum += n;
    c++;

    cout << "Unesi broj: ";
    cin >> n;
  }
  
  cout << "Prosjek je " << sum/c << endl;
  
  return 0;
}
