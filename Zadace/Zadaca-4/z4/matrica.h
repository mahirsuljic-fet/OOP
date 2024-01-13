#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename T>
class Matrica
{
  public:
    Matrica();
    Matrica(size_t m, size_t n) : _m(m), _n(n), _elements(new T[m * n]) { }
    Matrica(const std::initializer_list<T>&);
    Matrica(Matrica&&);
    Matrica(const Matrica&);
    ~Matrica() { delete[] _elements; }

    Matrica operator+(const Matrica&);
    Matrica operator+(const Matrica&) const;
    Matrica operator-(const Matrica&);
    Matrica operator-(const Matrica&) const;
    Matrica operator*(const double&);
    Matrica operator*(const double&) const;
    Matrica operator/(const double&);
    Matrica operator/(const double&) const;
    Matrica& operator=(Matrica&&);
    Matrica& operator=(const Matrica&);
    Matrica& operator+=(const Matrica&);
    Matrica& operator-=(const Matrica&);
    Matrica& operator*=(const double&);
    Matrica& operator/=(const double&);
    T& operator()(size_t, size_t);
    const T& operator()(size_t, size_t) const;

    size_t rows() const { return _m; }
    size_t columns() const { return _n; }

  private:
    size_t _m;
    size_t _n;
    T* _elements;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrica<T>& mat);

template <typename T>
Matrica<T>::Matrica(const std::initializer_list<T>& list)
{
  if (list.size() < 2) throw std::invalid_argument("Lista za inicijalizaciju nije validna!");

  auto it = list.begin();

  _m = *it++;
  _n = *it++;

  if (_m * _n > list.size() - 2) throw std::domain_error("Lista ima vise clanova nego navedeno!");

  _elements = new T[_m * _n];

  for (auto i = 2; i < list.size(); ++i)
    _elements[i - 2] = *it++;
}

template <typename T>
Matrica<T>::Matrica(Matrica<T>&& other) : _m(other._m), _n(other._n), _elements(other._elements)
{
  other._m = 0;
  other._n = 0;
  other._elements = nullptr;
}

template <typename T>
Matrica<T>::Matrica(const Matrica<T>& other) : _m(other._m), _n(other._n), _elements(new T[_m * _n])
{
  for (auto i = 0; i < _m * _n; ++i)
    _elements[i] = other._elements[i];
}

template <typename T>
Matrica<T>& Matrica<T>::operator=(Matrica<T>&& other)
{
  delete[] _elements;

  _m = other._m;
  _n = other._n;
  _elements = other._elements;

  other._m = 0;
  other._n = 0;
  other._elements = nullptr;

  return *this;
}

template <typename T>
Matrica<T>& Matrica<T>::operator=(const Matrica<T>& other)
{
  _m = other._m;
  _n = other._n;
  _elements = new T[_m * _n];

  for (auto i = 0; i < _m * _n; ++i)
    _elements[i] = other._elements[i];

  return *this;
}

template <typename T>
Matrica<T> Matrica<T>::operator+(const Matrica<T>& other)
{
  if (_m * _n != other._m * other._n) throw std::domain_error("Matrice nisu iste velicine!");

  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] += other._elements[i];

  return result;
}

template <typename T>
Matrica<T> Matrica<T>::operator+(const Matrica<T>& other) const
{
  if (_m * _n != other._m * other._n) throw std::domain_error("Matrice nisu iste velicine!");

  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] += other._elements[i];

  return result;
}

template <typename T>
Matrica<T> Matrica<T>::operator-(const Matrica<T>& other)
{
  if (_m * _n != other._m * other._n) throw std::domain_error("Matrice nisu iste velicine!");

  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] -= other._elements[i];

  return result;
}

template <typename T>
Matrica<T> Matrica<T>::operator-(const Matrica<T>& other) const
{
  if (_m * _n != other._m * other._n) throw std::domain_error("Matrice nisu iste velicine!");

  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] -= other._elements[i];

  return result;
}

template <typename T>
Matrica<T> Matrica<T>::operator*(const double& k)
{
  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] *= k;

  return result;
}

template <typename T>
Matrica<T> Matrica<T>::operator*(const double& k) const
{
  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] *= k;

  return result;
}

template <typename T>
Matrica<T> Matrica<T>::operator/(const double& k)
{
  if (k == 0) throw std::domain_error("Nije dozvoljeno dijeljenje sa nulom");

  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] /= k;

  return result;
}

template <typename T>
Matrica<T> Matrica<T>::operator/(const double& k) const
{
  if (k == 0) throw std::domain_error("Nije dozvoljeno dijeljenje sa nulom");

  Matrica<T> result(*this);
  for (auto i = 0; i < _m * _n; ++i)
    result._elements[i] /= k;

  return result;
}

template <typename T>
Matrica<T>& Matrica<T>::operator+=(const Matrica<T>& other)
{
  return *this = *this + other;
}

template <typename T>
Matrica<T>& Matrica<T>::operator-=(const Matrica<T>& other)
{
  return *this = *this - other;
}

template <typename T>
Matrica<T>& Matrica<T>::operator*=(const double& k)
{
  return *this = *this * k;
}

template <typename T>
Matrica<T>& Matrica<T>::operator/=(const double& k)
{
  if (k == 0) throw std::domain_error("Nije dozvoljeno dijeljenje sa nulom");
  return *this = *this / k;
}

template <typename T>
T& Matrica<T>::operator()(size_t i, size_t j)
{
  return _elements[i * _n + j];
}

template <typename T>
const T& Matrica<T>::operator()(size_t i, size_t j) const
{
  return _elements[i * _n + j];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrica<T>& mat)
{
  for (auto i = 0; i < mat.rows(); ++i)
  {
    for (auto j = 0; j < mat.columns(); ++j)
      os << mat(i, j) << "\t";
    os << std::endl;
  }

  return os;
}
