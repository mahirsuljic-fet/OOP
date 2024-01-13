#include <iostream>
#include <iterator>
#include <string>
#include <vector>

struct Foo
{
    int a;
    double b;

    struct Bar
    {
        char k;
        float f;
    };
};

Foo c { 5, 3.3 };
Foo::Bar z;

typedef std::vector<Foo> Kontejner;

int main(int argc, char* argv[])
{
  std::vector<int> vec = { 5, 10, 2, 1 };

  auto t = std::begin(vec);
  auto p = std::end(vec);

  /*
   * ++(++a) - validno, ++a vraca a, kao varijablu
   * (a++)++ - nije validno jer a++ vraca vrijednost, nema rezervisan komad memorije
   */

  std::vector<int>::iterator it_vec = std::begin(vec);
  std::vector<int>::const_iterator cit_vec = std::begin(vec);

  // *cit_vec = c;  nije validno, const_iterator ne dozvoljava promjenu vrijednosti,
  //                svi ostali operatori su dozvoljeni i isti kao kod obicnog iteratora

  // svaki container ima svoj iterator koji se klasificira u neku od katerorija iteratora

  Kontejner v {
    Foo { 2, 3.3 },
    Foo { 4, 2.2 }
  };

  auto it = std::begin(v);

  auto& z = *it;
  z.a = 55;

  (*it).a = 55;

  it->a = 55;

  return 0;
}
