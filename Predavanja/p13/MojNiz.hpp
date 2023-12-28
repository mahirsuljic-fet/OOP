#pragma once

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <ostream>

class MojNiz
{
  public:
    MojNiz(std::initializer_list<int> a) :
      p_ { new int[n_] }, n_ { a.size() }
    {
      std::copy(begin(a), end(a), p_);
    }

    // COPY KONSTRUKTOR
    MojNiz(const MojNiz& drugi) :
      p_ { new int[n_] }, n_ { drugi.n_ }
    {
      std::copy(drugi.p_, drugi.p_ + drugi.n_, p_);
    }

    // MOVE KONSTRUKTOR
    MojNiz(MojNiz&& drugi) :
      p_ { drugi.p_ }, n_ { drugi.n_ }
    {
      // pri umiranju objekta poziva se destruktor koji u ovom slucaju
      // brise podatke koji su se nalazili na p_
      // da se podaci koje zelimo premjestiti ne bi izbrisali
      // potrebno je da prekinemo vezu izmedju tih podatada i objekta drugi
      // to radimo tako sto drugi.p_ postavimo na nullptr
      // te se destruktorom nece nista izbrisat jer nullptr ne pokazuje ni na sta
      drugi.p_ = nullptr;
      drugi.n_ = 0;
    }

    // DESTRUKTOR
    ~MojNiz() { delete[] p_; }

    // OPERATOR =, COPY, za kad je sa desne strane lvalue
    MojNiz& operator=(const MojNiz& drugi)
    {
      if (this != &drugi)
      {
        delete[] p_;
        n_ = drugi.n_;
        p_ = new int[n_];
        std::copy(drugi.p_, drugi.p_ + n_, p_);
      }
      return *this;
    }

    // OPERATOR =, MOVE, za kad je sa desne strane rvalue
    MojNiz& operator=(MojNiz&& drugi)
    {
      // ne treba if kao u COPY, jer this je lvalue,
      // a drugi je rvalue pa nikad ne mogu biti isti
      delete[] p_;

      p_ = drugi.p_;
      n_ = drugi.n_;

      drugi.p_ = nullptr;
      drugi.n_ = 0;

      return *this;
    }

    size_t size() const { return n_; }

    int& at(size_t i)
    {
      if (i >= size()) throw 2.5; // 2.5 je onako bezveze, cisto da ima nesto
      return p_[i];
    }

    const int& at(size_t i) const
    {
      if (i >= size()) throw 2.5;
      return p_[i];
    }

    int operator[](int i)
    {
      return p_[i];
    }

    void printaj(std::ostream& izlaz = std::cout) const
    {
      for (int i = 0; i < n_; i++)
        izlaz << p_[i] << " ";
    }

  private:
    size_t n_ { 0 };
    int* p_ { nullptr };
};
