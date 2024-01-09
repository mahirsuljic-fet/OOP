#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <ostream>

class MojNizInt
{
  private:
    int* _p;
    size_t _size;

  public:
    MojNizInt();
    MojNizInt(const std::initializer_list<int>&);
    MojNizInt(MojNizInt&&);
    MojNizInt(const MojNizInt&);
    ~MojNizInt();

    MojNizInt& operator=(MojNizInt&&);
    MojNizInt& operator=(const MojNizInt&);
    int& operator[](int n) { return _p[n]; };
    const int& operator[](int n) const { return _p[n]; };
    MojNizInt operator*(int);
    MojNizInt operator*(int) const;
    MojNizInt operator+(const MojNizInt&);
    MojNizInt operator+(const MojNizInt&) const;
    MojNizInt& operator++();
    MojNizInt operator++(int);

    int& at(int);
    const int& at(int) const;
    size_t size() const { return _size; }
    void print(std::ostream& = std::cout) const;
    MojNizInt& push_back(int);
};

MojNizInt operator*(int, const MojNizInt& niz);
