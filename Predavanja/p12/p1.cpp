#include "../../usefulminifuncs.cpp"
#include "MojVector.h"
#include <iostream>

// void foo()
// {
//   MojVector v { 3, 5, -1 };
//   printaj(v);
// }

int main(int argc, char* argv[])
{
  // MojVector v { 3, 5, -1 };
  // MojVector v1 { v };
  // MojVector v2 = v;

  MojVector v1 { 3, 5, -1 };
  MojVector v2 { 10, 100 };

  v1 = v2;
  v1 = v1;

  return 0;
}
