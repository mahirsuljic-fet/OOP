#include "MojNizInt.hpp"
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>

MojNizInt::MojNizInt()
{
  this->_p = nullptr;
  this->_size = 0;
}

MojNizInt::MojNizInt(const std::initializer_list<int>& list)
{
  _p = new int[list.size()];
  _size = list.size();

  int* it = _p;
  for (auto& el : list)
    *it++ = el;
}

MojNizInt::MojNizInt(MojNizInt&& original)
{
  delete[] _p;

  _p = original._p;
  _size = original._size;

  original._p = nullptr;
  original._size = 0;
}

MojNizInt::MojNizInt(const MojNizInt& original)
{
  _p = new int[original._size];
  _size = original._size;

  for (auto i = 0; i < _size; ++i)
    _p[i] = original._p[i];
}

MojNizInt& MojNizInt::operator=(MojNizInt&& other)
{
  if (this != &other)
  {
    delete[] _p;

    _p = other._p;
    _size = other._size;

    other._p = nullptr;
    other._size = 0;
  }

  return *this;
}

MojNizInt& MojNizInt::operator=(const MojNizInt& other)
{
  if (this != &other)
  {
    delete[] _p;

    _p = new int[other._size];
    _size = other._size;

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
  MojNizInt result;

  result._p = new int[_size];
  result._size = _size;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] * k;

  return result;
}

MojNizInt MojNizInt::operator*(int k) const
{
  MojNizInt result;

  result._p = new int[_size];
  result._size = _size;

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

  MojNizInt result;

  result._p = new int[_size];
  result._size = _size;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i] + other._p[i];

  return result;
}

MojNizInt MojNizInt::operator+(const MojNizInt& other) const
{
  if (_size != other._size) throw std::invalid_argument("Nizovi nisu iste duzine!");

  MojNizInt result;

  result._p = new int[_size];
  result._size = _size;

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
  MojNizInt result;

  result._p = new int[_size];
  result._size = _size;

  for (auto i = 0; i < _size; ++i)
    result._p[i] = _p[i]++;

  return result;
}

MojNizInt& MojNizInt::push_back(int n)
{
  int* p_new = new int[_size + 1];

  for (auto i = 0; i < _size; ++i)
    p_new[i] = _p[i];

  p_new[_size++] = n;

  delete[] _p;
  _p = p_new;

  return *this;
}
