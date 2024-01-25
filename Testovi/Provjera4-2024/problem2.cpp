#include <algorithm>
#include <cstddef>
#include <initializer_list>

// Da li su implementirani konstruktori validni, ako ne zasto?
// Implementirati copy konstruktor, copy operator = i destruktor.

// implementirani konstruktori su validni.

class MojNiz
{
  public:
    MojNiz() = default;

    MojNiz(std::initializer_list<int> l)
      : size_(l.size()), capacity_(l.size() * 2), data_(new int[capacity_])
    {
      std::copy(l.begin(), l.end(), data_);
    }

    MojNiz(MojNiz&& o)
      : size_(o.size_), capacity_(o.capacity_), data_(o.data_)
    {
      o.size_ = 0;
      o.capacity_ = 0;
      o.data_ = nullptr;
    }

    // dodane metode:
    MojNiz(const MojNiz& other)
      : size_(other.size_), capacity_(other.capacity_), data_(new int[other.capacity_])
    {
      std::copy(other.data_, other.data_ + size_, data_);
    }

    MojNiz& operator=(const MojNiz& other)
    {
      delete[] data_;

      size_ = other.size_;
      capacity_ = other.capacity_;
      data_ = new int[capacity_];

      std::copy(other.data_, other.data_ + size_, data_);

      return *this;
    }

    ~MojNiz() { delete[] data_; }

  private:
    size_t size_ = 0;
    size_t capacity_ = 2;
    int* data_ = new int[capacity_];
};
