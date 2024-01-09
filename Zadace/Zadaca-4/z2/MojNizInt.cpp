#include "MojNizInt.hpp"
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>

MojNizInt::MojNizInt()
{
  _size = 0;
  _cap = 1;
  _p = new int[_cap];
}

MojNizInt::MojNizInt(const bool& b)
{
  _size = 0;
  _cap = 1;

  if (b)
    _p = new int[_cap];
  else
    _p = nullptr;
}

MojNizInt::MojNizInt(const std::initializer_list<int>& list)
{
  _p = new int[list.size()];
  _size = list.size();
  _cap = list.size();

  int* it = _p;
  for (auto& el : list)
    *it++ = el;
}

MojNizInt::MojNizInt(MojNizInt&& original)
{
  delete[] _p;

  _p = original._p;
  _cap = original._cap;
  _size = original._size;

  original._cap = 1;
  original._size = 0;
  original._p = new int[_cap];
}

MojNizInt::MojNizInt(const MojNizInt& original)
{
  _p = new int[original._cap];
  _size = original._size;
  _cap = original._cap;

  for (auto i = 0; i < _size; ++i)
    _p[i] = original._p[i];
}

MojNizInt& MojNizInt::operator=(MojNizInt&& other)
{
  if (this != &other)
  {
    delete[] _p;

    _p = other._p;
    _cap = other._cap;
    _size = other._size;

    other._cap = 1;
    other._size = 0;
    other._p = new int[_cap];
  }

  return *this;
}

MojNizInt& MojNizInt::operator=(const MojNizInt& other)
{
  if (this != &other)
  {
    delete[] _p;

    _p = new int[other._cap];
    _size = other._size;
    _cap = other._cap;

    for (auto i = 0; i < _size; ++i)
      _p[i] = other._p[i];
  }

  return *this;
}

MojNizInt::~MojNizInt()
{
  delete[] _p;
}

void MojNizInt::print(std::ostream& os) const
{
  if (_size == 0) return;

  for (auto i = 0; i < _size; ++i)
    os << _p[i] << " ";
  os << std::endl;
}

int& MojNizInt::at(int n)
{
  if (n < 0 || n >= _size) throw std::invalid_argument("Zabranjen pristup van granica niza!");
  return _p[n];
}

const int& MojNizInt::at(int n) const
{
  if (n < 0 || n >= _size) throw std::invalid_argument("Zabranjen pristup van granica niza!");
  return _p[n];
}

MojNizInt MojNizInt::operator*(int k)
{
  MojNizInt result(false);

  result._p = new int[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] * k;

  return result;
}

MojNizInt MojNizInt::operator*(int k) const
{
  MojNizInt result(false);

  result._p = new int[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] * k;

  return result;
}

MojNizInt operator*(int k, const MojNizInt& niz)
{
  return niz * k;
}

MojNizInt MojNizInt::operator+(const MojNizInt& other)
{
  if (_size != other._size) throw std::invalid_argument("Nizovi nisu iste duzine!");

  MojNizInt result(false);

  result._p = new int[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] + other._p[i];

  return result;
}

MojNizInt MojNizInt::operator+(const MojNizInt& other) const
{
  if (_size != other._size) throw std::invalid_argument("Nizovi nisu iste duzine!");

  MojNizInt result(false);

  result._p = new int[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] + other._p[i];

  return result;
}

MojNizInt& MojNizInt::operator++()
{
  for (auto i = 0; i < _size; ++i)
    ++_p[i];

  return *this;
}

MojNizInt MojNizInt::operator++(int)
{
  MojNizInt result(false);

  result._p = new int[_cap];
  result._size = _size;
  result._cap = _cap;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i]++;

  return result;
}

MojNizInt& MojNizInt::push_back(int n)
{
  if (_size == _cap)
  {
    _cap *= 2;
    int* p_new = new int[_cap];

    for (auto i = 0; i < _size; ++i)
      p_new[i] = _p[i];

    delete[] _p;
    _p = p_new;
  }

  _p[_size++] = n;

  return *this;
}

MojNizInt& MojNizInt::pop_back()
{
  --_size;
  return *this;
}
