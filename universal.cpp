#include "usefulminifuncs.cpp"
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>

template <typename T>
class Foo
{
  private:
    T* _p;
    size_t _size;

  public:
    // konstruktori i destruktor
    Foo(const std::initializer_list<T>&);
    template <typename U>
    Foo(const std::initializer_list<U>&);
    ~Foo() { delete[] _p; }

    // problematicni operator
    template <typename U>
    Foo<T>& operator=(Foo<U>&&);

    // pomocne metode
    void print(std::ostream& os = std::cout) const;
    size_t size() const { return _size; }
    T& front() const { return _p[0]; }
    void clean()
    {
      _p = nullptr;
      _size = 0;
    }
};

template <typename T>
Foo<T>::Foo(const std::initializer_list<T>& list)
{
  std::cout << "IC - T\n";

  _p = new T[list.size()];
  _size = list.size();

  T* it = _p;
  for (auto& el : list)
    *it++ = el;
}

template <typename T>
template <typename U>
Foo<T>::Foo(const std::initializer_list<U>& list)
{
  std::cout << "IC - TU\n";

  _p = new T[list.size()];
  _size = list.size();

  T* it = _p;
  for (auto& el : list)
    *it++ = el;
}

template <typename T>
void Foo<T>::print(std::ostream& os) const
{
  for (auto i = 0; i < _size; ++i)
    os << _p[i] << " ";
  os << std::endl;
}

//========================================================================================

template <typename T>
template <typename U>
Foo<T>& Foo<T>::operator=(Foo<U>&& other)
{
  delete[] _p;

  // _p = other._p;
  // _p = (T*)other._p;

  // PITANJE IZ OVOG PRIMJERA
  //
  // Da li je moguce napraviti ovakav move operator= kada imamo razlicite tipove pointera?

  // GLAVNO PITANJE
  //
  // Da li je uopce pametno raditi konverziju tipova kada radimo sa pointerima,
  // i ako da, koji je pravilan nacin da se to odradi?

  _p = (T*)&other.front(); // kompajlat ce ali ne valja jer bukvalno preuzme bajtove
  _size = other.size();

  other.clean();

  return *this;
}

//========================================================================================

int main(int argc, char* argv[])
{
  Foo<int> i = { 1, 2, 3 };
  Foo<double> d = { 4, 5, 6 };

  i.print();
  d.print();

  d = std::move(i);
  // ili
  // i = std::move(d);

  i.print();
  d.print();

  return 0;
}
