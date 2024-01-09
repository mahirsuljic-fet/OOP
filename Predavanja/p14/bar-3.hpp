#pragma once

// implementacija metoda generickih tipova pisemo u hpp fajlu

template <typename T, typename U>
struct par
{
    T prvi;
    U drugi;

    bool operator==(const par<T, U>& d) const;
};

//????????????????????????????????????
//====================================

// template <typename T, typename U>
// par<int, double> test(par<T, U> a)
// {
//   return a;
// }

//====================================
//????????????????????????????????????

template <typename A, typename X>
// bool par<A, X>::operator==(const par& d) const // moze se izostavit <A,X> u parametru
bool par<A, X>::operator==(const par<A, X>& d) const
{
  return prvi == d.prvi && drugi == d.drugi;
}

template <typename A, typename B>
par<A, B> kreirajPar(A a, B b)
{
  return par<A, B> { a, b };
}
