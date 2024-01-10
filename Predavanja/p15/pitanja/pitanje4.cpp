#include <iostream>

//=======================================================================================//
//                                     PITANJE 4 ...                                     //
//=======================================================================================//

// value i reference?

struct Bar
{
    int n;

    Bar(int x) :
      n { x } { }
};

// termini lvalue, xvalue, glvalue, rvalue, prvalue
// xvalue je malo zbunjujuci, sta je tacno?
// sta je univerzalna referenca, kakve ima veze sa ovih 5 tipova i kada je koristiti (kod generickih izraza?)?

void ref(int&); // lvalue ref
void ref(int&&); // rvalue ref
template <typename T>
void ref(T&&); // univerzalna (forwarding) ref?
template <typename T>
void ref(T&); // lvalue ref?

// sta radi std::forward, za sta sluzi i da li ima slicnosti sa std::move?

int main(int argc, char* argv[])
{

  return 0;
}
