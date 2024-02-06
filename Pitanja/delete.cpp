#include <cstddef>
#include <iostream>

int main(int argc, char* argv[])
{
  size_t arr_size = 5;
  int* arr_p = new int[arr_size];

  for (int i = 0; i < arr_size; ++i) arr_p[i] = i; // cisto da ima neke podatke

  delete[] arr_p;
  // Kako delete[] zna sta da izbrise (koliko memorije)?
  // Da li se negdje cuva podatak koliko memorije zauzima arr?
  // Ako da, da li mi mozemo pristupiti tom podatku?

  int arr[] = { 1, 2, 3 };
  std::cout << sizeof(arr) << std::endl;

  // Ovo postoji za niz na stack-u, da li postoji nesto
  // slicno za dinamicki alocirani niz (na heap-u)?

  return 0;
}
