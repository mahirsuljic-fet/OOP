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
  _p = new T[list.size()];
  _size = list.size();

  T* it = _p;
  for (const auto& el : list)
    *it++ = el;
}

template <typename T>
template <typename U>
Foo<T>::Foo(const std::initializer_list<U>& list)
{
  _p = new T[list.size()];
  _size = list.size();

  T* it = _p;
  for (const auto& el : list)
    *it++ = el;
}

template <typename T>
void Foo<T>::print(std::ostream& os) const
{
  for (auto i = 0; i < _size; ++i)
    os << _p[i] << " ";
  os << std::endl;
}

//=======================================================================================//
//                                     PITANJE 2                                         //
//=======================================================================================//

// move konstruktor izmedju dva objekta genericke klase koji su instancirani razlicitim tipovima?

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
  // Da li je uopce ima smisla i da li je pametno raditi konverziju tipova kada
  // radimo sa pointerima, i ako da, koji je pravilan nacin da se to odradi?

  _p = (T*)&other.front(); // kompajlat ce ali ne valja jer bukvalno preuzme bajtove
  _size = other.size();

  other.clean();

  return *this;
}

int main(int argc, char* argv[])
{
  Foo<int> i = { 1, 2, 3 };
  Foo<long> l = { 1, 2, 3 };
  Foo<double> d = { 4, 5, 6 };

  i.print();
  l.print();
  d.print();

  //=======================================================================================//
  //                                        PITANJE 3                                      //
  //=======================================================================================//

  // error: heap buffer overflow?

  // MINI DISKUSIJA
  //
  // pitanje:
  // zasto se desava u jednom slucaju a ne u drugom?
  //
  // odgovor?:
  // (razlicite velicine? double > int (error), double == long (OK)?)
  // objekat i zauzima 3*4 bajta, kada ga premjestimo u d,
  // a zatim pokusamo printati d, pokusajemo printati 3*8 bajta
  // te dolazimu u memoriju koja nije nasa

  // GLAVNO PITANJE
  //
  // sta je tacno heap buffer overflow?
  // da li se desava samo kada pokusamo pristupiti
  // memoriji koju nismo zauzeli?

  d = std::move(i); // error: heap buffer overflow
  // d = std::move(l); // ok
  // i = std::move(d); // ok

  i.print();
  l.print();
  d.print();

  return 0;
}
