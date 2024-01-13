#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <ostream>

template <typename T>
class MojNiz
{
  private:
    T* _p;
    size_t _size;

  public:
    // MojNiz(const std::initializer_list<T>&);
    template <typename U>
    MojNiz(const std::initializer_list<U>&);
};

//=======================================================================================//
//                                     PITANJE 6                                         //
//=======================================================================================//

// template <typenamG T>
// MojNiz<T>::MojNiz(const std::initializer_list<T>& list)
// {
//   _p = new T[list.size()];
//   _size = list.size();
//
//   T* it = _p;
//   for (auto& el : list)
//     *it++ = el;
// }

template <typename T>
template <typename U>
MojNiz<T>::MojNiz(const std::initializer_list<U>& list)
{
  _p = new T[list.size()];
  _size = list.size();

  T* it = _p;
  for (auto& el : list)
    *it++ = el;
}

int main(int argc, char* argv[])
{
  MojNiz<int> a = { 1, 2, 3, 4 };

  return 0;
}
