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
    size_t _cap;

  public:
    MojNizInt();
    MojNizInt(const bool&);
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
    int& front() const { return _p[0]; };
    int& back() const { return _p[_size - 1]; };
    size_t size() const { return _size; }
    size_t capacity() const { return _cap; }
    void print(std::ostream& = std::cout) const;
    MojNizInt& push_back(int);
    MojNizInt& pop_back();
};

MojNizInt operator*(int, const MojNizInt& niz);
