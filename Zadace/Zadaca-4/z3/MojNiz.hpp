#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename T>
class MojNiz
{
  private:
    T* _p;
    size_t _size;
    size_t _cap;

  public:
    MojNiz();
    MojNiz(const bool&);
    MojNiz(const std::initializer_list<T>&);
    template <typename U>
    MojNiz(const std::initializer_list<U>&);
    MojNiz<T>(MojNiz<T>&&);
    MojNiz(const MojNiz<T>&);
    template <typename U>
    MojNiz(const MojNiz<U>&);
    ~MojNiz();

    T& at(int);
    const T& at(int) const;
    T& front() const { return _p[0]; };
    T& back() const { return _p[_size - 1]; };
    size_t size() const { return _size; }
    size_t capacity() const { return _cap; }
    void print(std::ostream& = std::cout) const;
    void clear();
    void clean();
    MojNiz<T>& push_back(T);
    MojNiz<T>& pop_back();

    MojNiz<T>& operator=(MojNiz<T>&&);
    MojNiz<T>& operator=(const MojNiz<T>&);
    template <typename U>
    MojNiz<T>& operator=(const MojNiz<U>&);
    T& operator[](int n) { return _p[n]; };
    const T& operator[](int n) const { return _p[n]; };
    MojNiz<T> operator*(T);
    template <typename U>
    MojNiz<T> operator*(U);
    MojNiz<T> operator*(T) const;
    template <typename U>
    MojNiz<T> operator*(U) const;
    MojNiz<T> operator+(const MojNiz<T>&);
    template <typename U>
    auto operator+(const MojNiz<U>& other)
      -> MojNiz<decltype(this->front() + other.front())>;
    MojNiz<T> operator+(const MojNiz<T>&) const;
    template <typename U>
    auto operator+(const MojNiz<U>& other) const
      -> MojNiz<decltype(this->front() + other.front())>;
    MojNiz<T>& operator++();
    MojNiz<T> operator++(int);
};

template <typename T>
MojNiz<T>::MojNiz()
{
  // std::cout << "DC - T\n";

  _size = 0;
  _cap = 1;
  _p = new T[_cap];
}

template <typename T>
MojNiz<T>::MojNiz(const bool& b)
{
  // std::cout << "Cb - T\n";

  _size = 0;
  _cap = 1;

  if (b)
    _p = new T[_cap];
  else
    _p = nullptr;
}

template <typename T>
MojNiz<T>::MojNiz(const std::initializer_list<T>& list)
{
  // std::cout << "IC - T\n";

  _p = new T[list.size()];
  _size = list.size();
  _cap = list.size();

  T* it = _p;
  for (auto& el : list)
    *it++ = el;
}

template <typename T>
template <typename U>
MojNiz<T>::MojNiz(const std::initializer_list<U>& list)
{
  // std::cout << "IC - TU\n";

  _p = new T[list.size()];
  _size = list.size();
  _cap = list.size();

  T* it = _p;
  for (auto& el : list)
    *it++ = el;
}

template <typename T>
MojNiz<T>::MojNiz(MojNiz<T>&& original)
{
  // std::cout << "MC - T\n";

  _p = original._p;
  _cap = original._cap;
  _size = original._size;

  original.clean();
}

template <typename T>
MojNiz<T>::MojNiz(const MojNiz<T>& original)
{
  // std::cout << "CC - T\n";

  _p = new T[original._cap];
  _size = original._size;
  _cap = original._cap;

  for (auto i = 0; i < _size; ++i)
    _p[i] = original._p[i];
}

template <typename T>
template <typename U>
MojNiz<T>::MojNiz(const MojNiz<U>& original)
{
  // std::cout << "CC - TU\n";

  _p = new T[original.capacity()];
  _size = original.size();
  _cap = original.capacity();

  for (auto i = 0; i < _size; ++i)
    _p[i] = *(&original.front() + i);
}

template <typename T>
MojNiz<T>& MojNiz<T>::operator=(MojNiz<T>&& other)
{
  // std::cout << "M= - T\n";

  if (this != &other)
  {
    delete[] _p;

    _p = other._p;
    _cap = other._cap;
    _size = other._size;

    other.clean();
  }

  return *this;
}

template <typename T>
MojNiz<T>& MojNiz<T>::operator=(const MojNiz<T>& other)
{
  // std::cout << "C= - T\n";

  if (this != &other)
  {
    delete[] _p;

    _p = new T[other.capacity()];
    _size = other.size();
    _cap = other.capacity();

    for (auto i = 0; i < _size; ++i)
      _p[i] = other._p[i];
  }

  return *this;
}

template <typename T>
template <typename U>
MojNiz<T>& MojNiz<T>::operator=(const MojNiz<U>& other)
{
  // std::cout << "C= - TU\n";

  delete[] _p;

  _p = new T[other.capacity()];
  _size = other.size();
  _cap = other.capacity();

  for (auto i = 0; i < _size; ++i)
    _p[i] = other[i];

  return *this;
}

template <typename T>
MojNiz<T>::~MojNiz()
{
  // std::cout << "D\n";

  delete[] _p;
}

template <typename T>
void MojNiz<T>::print(std::ostream& os) const
{
  // ne komentarisan - ne printaj nista kada je niz prazan
  // komentarisan    - printaj std::endl i kada je niz prazan
  // if (_size == 0) return;

  for (auto i = 0; i < _size; ++i)
    os << _p[i] << " ";
  os << std::endl;
}

template <typename T>
T& MojNiz<T>::at(int n)
{
  if (n < 0 || n >= _size) throw std::invalid_argument("Zabranjen pristup van granica niza!");
  return _p[n];
}

template <typename T>
const T& MojNiz<T>::at(int n) const
{
  if (n < 0 || n >= _size) throw std::invalid_argument("Zabranjen pristup van granica niza!");
  return _p[n];
}

template <typename T>
MojNiz<T> MojNiz<T>::operator*(T k)
{
  MojNiz<T> result(false);

  result._p = new T[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] * k;

  return result;
}

template <typename T>
template <typename U>
MojNiz<T> MojNiz<T>::operator*(U k)
{
  MojNiz<T> result(false);

  result._p = new T[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] * k;

  return result;
}

template <typename T>
MojNiz<T> MojNiz<T>::operator*(T k) const
{
  MojNiz<T> result(false);

  result._p = new T[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] * k;

  return result;
}

template <typename T>
template <typename U>
MojNiz<T> MojNiz<T>::operator*(U k) const
{
  MojNiz<T> result(false);

  result._p = new T[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] * k;

  return result;
}

template <typename T>
MojNiz<T> operator*(T k, const MojNiz<T>& niz)
{
  return niz * k;
}

template <typename T>
MojNiz<T> MojNiz<T>::operator+(const MojNiz<T>& other)
{
  // std::cout << "+ - T\n";

  if (_size != other._size) throw std::invalid_argument("Nizovi nisu iste duzine!");

  MojNiz<T> result(false);

  result._p = new T[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] + other[i];

  return result;
}

template <typename T>
template <typename U>
auto MojNiz<T>::operator+(const MojNiz<U>& other)
  -> MojNiz<decltype(this->front() + other.front())>
{
  // std::cout << "+ - TU\n";

  if (_size != other.size()) throw std::invalid_argument("Nizovi nisu iste duzine!");
  if (_size == 0) return *this;

  MojNiz<decltype(this->front() + other.front())> result(*this);

  for (auto i = 0; i < _size; ++i)
    result[i] = _p[i] + other[i];

  return result;
}

template <typename T>
MojNiz<T> MojNiz<T>::operator+(const MojNiz<T>& other) const
{
  // std::cout << "+c - T\n";

  if (_size != other._size) throw std::invalid_argument("Nizovi nisu iste duzine!");

  MojNiz<T> result(false);

  result._p = new T[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] + other._p[i];

  return result;
}

template <typename T>
template <typename U>
auto MojNiz<T>::operator+(const MojNiz<U>& other) const
  -> MojNiz<decltype(this->front() + other.front())>
{
  // std::cout << "+c - TU\n";

  if (_size != other.size()) throw std::invalid_argument("Nizovi nisu iste duzine!");
  if (_size == 0) return *this;

  MojNiz<decltype(this->front() + other.front())> result(*this);

  for (auto i = 0; i < _size; ++i)
    result[i] = _p[i] + other[i];

  return result;
}

template <typename T>
MojNiz<T>& MojNiz<T>::operator++()
{
  for (auto i = 0; i < _size; ++i)
    ++_p[i];

  return *this;
}

template <typename T>
MojNiz<T> MojNiz<T>::operator++(int)
{
  MojNiz<T> result(false);

  result._p = new T[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i]++;

  return result;
}

template <typename T>
MojNiz<T>& MojNiz<T>::push_back(T n)
{
  if (_size == _cap)
  {
    _cap *= 2;
    T* p_new = new T[_cap];

    for (auto i = 0; i < _size; ++i)
      p_new[i] = _p[i];

    delete[] _p;
    _p = p_new;
  }

  _p[_size++] = n;

  return *this;
}

template <typename T>
MojNiz<T>& MojNiz<T>::pop_back()
{
  if (_size > 0)
    --_size;
  return *this;
}

template <typename T>
void MojNiz<T>::clear()
{
  _size = 0;
  _cap = 1;

  delete[] _p;
  _p = new T[_cap];
}

template <typename T>
void MojNiz<T>::clean()
{
  _size = 0;
  _cap = 1;
  _p = nullptr;
}
