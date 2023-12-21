#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>

// push_back() odradit za vjezbu

struct MojVector
{
    size_t br = 0; // broj elemenata; size_t je typedef za unsigned int
    int* p = nullptr; // pointer na heap gdje ce se nalazit elementi

    MojVector(const std::initializer_list<int>& list) :
      br { list.size() }, p { new int[br] }
    {
      std::copy(list.begin(), list.end(), p);
    }

    MojVector(const MojVector& d) :
      br { d.br }, p { new int[br] }
    {
      std::copy(d.p, d.p + br, p);
    }

    ~MojVector() { delete[] p; }

    MojVector& operator=(const MojVector& d)
    {
      if (this == &d) // za slucaj v1 = v1
      {
        delete[] p;

        br = d.br;
        p = new int[br];

        std::copy(d.p, d.p + br, p);
      }

      return *this;
    }

    size_t size() const { return br; }
    int& at(size_t i) { return p[i]; } // poziva se ako je objekat MojVector
    const int& at(size_t i) const { return p[i]; } // poziva se ako je objekat const MojVector
};

// ovo ne valja radit, al eto, moze nam se
//
// ne valja jer ce svaki put kad se napravi
// objekat strukture MojVector najbolje
// je u odvojenom cpp fajlu definisat
inline void printaj(const MojVector& v)
{
  for (auto i = 0; i < v.size(); ++i)
    std::cout << v.at(i) << " ";
  std::cout << std::endl;
}
