#include <iostream>

struct Bazna
{
  private:
    int a;

  public: // redundancija, ne treba jer je struct
    int b;

    void tar() { a = 10; }

  protected:
    int c;

    void tar_pr() { a = 20; }
};

// struct Izvedena : public Bazna
// {
//     void foo_tar_pr() { tar_pr(); }
// };

struct Izvedena : private Bazna
{
    // a = 2; // greska jer je a private

    void foo() { b = 100; }
    void foo_tar() { tar(); }
    void foo_tar_pr() { tar_pr(); }
};

// struct Izvecena : Bazna // isto kao i : public Bazna
// {
//     void foo() { tar(); }
// }

// class Izvedena : Bazna // isto kao i : private Bazna
// {
// }

int main(int argc, char* argv[])
{
  Izvedena i;
  // i.b = 25;
  // i.foo();
  // i.foo_tar();
  // i.foo_tar_pr();
  // i.tar_pr();

  return 0;
}
