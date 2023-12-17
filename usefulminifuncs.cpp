#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

// funkcija koja vraca vector cijelih brojeva od n_element elemenata koji imaju random vrijednosti
// n_start oznacava najmanju mogucu vrijednost random broja
// n_end oznacava najvecu mogucu vrijednost random broja
//
// Npr. za argumente (3) vraca vector { 6, 0, 10 } - random vrijednosti izmedju 0 i 10
std::vector<int> random_vector_int(
  const unsigned int& n_element,
  const int& n_start = 0,
  const int& n_end = 10);

// funkcija koja vraca vector cijelih brojeva od n_element elemenata
// od kojih prvi element ima vrijednost n_start i svaki naredni element
// je za n_inc veci od prethodnog
//
// Npr. za argumente (3, 2, 2) vraca vector { 2, 4, 6 }
std::vector<int> ordered_vector_int(
  const unsigned int& n_element,
  const int& n_start = 0,
  const int& n_inc = 1);

// funkcija koja vraca listu cijelih brojeva od n_element elemenata koji imaju random vrijednosti
// n_start oznacava najmanju mogucu vrijednost random broja
// n_end oznacava najvecu mogucu vrijednost random broja
//
// Npr. za argumente (4) vraca listu { 0, 2, 10, 5 } - random vrijednosti izmedju 0 i 10
std::list<int> random_list_int(
  const unsigned int& n_element,
  const int& n_start = 0,
  const int& n_end = 10);

// funkcija koja vraca listu cijelih brojeva od n_element elemenata
// od kojih prvi element ima vrijednost n_start i svaki naredni element
// je za n_inc veci od prethodnog
//
// Npr. za argumente (4, 1, 3) vraca listu { 1, 4, 7, 10 }
std::list<int> ordered_list_int(
  const unsigned int& n_element,
  const int& n_start = 0,
  const int& n_inc = 1);

// funkcija koja vraca mapu sa kljucem string i vrijednosti int od n_element elemenata
// od kojih prvi element ima vrijednost kljuc prefix + n_start i vrijednost n_start
// a svaki naredni element ima kljuc kao i prethodni ali umjesto n_start je vrijednost
// veca za n_int, a vrijednost elementa je za n_inc veci od prethodnog
//
// Npr. za argumente (2, "test", 1, 2) vraca mapu { {"test1", 1}, {"test3", 3} }
std::map<std::string, int> ordered_map_string_int(
  const unsigned int& n_element,
  const std::string& prefix = "key",
  const int& n_start = 0,
  const int& n_inc = 1);

// funkcija koja vraca pointer na pocetak niza cijelih brojeva sa n_element elemenata
// od kojih prvi element ima vrijednost n_start i svaki naredni element
// je za n_inc veci od prethodnog
//
// Npr. za argumente (3, 5, 2) vraca vector { 5, 7, 9 }
int* ordered_array_int(
  const unsigned int& n_element,
  const int& n_start = 0,
  const int& n_inc = 1);

// funkcija koja vraca pointer na pocetak niza cijelih brojeva od n_element elemenata koji imaju random vrijednosti
// n_start oznacava najmanju mogucu vrijednost random broja
// n_end oznacava najvecu mogucu vrijednost random broja
//
// Npr. za argumente (4) vraca vector { 2, 10, 6, 0 } - random vrijednosti izmedju 0 i 10
int* random_array_int(
  const unsigned int& n_element,
  const int& n_start = 0,
  const int& n_end = 10);

// funkcija koja ispisuje container koji je vector elemenata tipa T
// prije ispisa containera se ispisuje prepend
// izmedju svakog elementa se printa seperate_string
// poslije ispisa containera se ispisuje append
template <typename T>
void print_container(
  const std::vector<T>& container,
  const std::string& seperate_string = " ",
  const std::string& prepend = "",
  const std::string& append = "\n");

// funkcija koja ispisuje container koji je list elemenata tipa T
// prije ispisa containera se ispisuje prepend
// izmedju svakog elementa se printa seperate_string
// poslije ispisa containera se ispisuje append
template <typename T>
void print_container(
  const std::list<T>& container,
  const std::string& seperate_string = " ",
  const std::string& prepend = "",
  const std::string& append = "\n");

// funkcija koja ispisuje container koji je mapa
// ciji elemenati imaju kljuc tipa Key i vrijednosti tipa T
// prije ispisa containera se ispisuje prepend
// izmedju kljuca i vrijednosti se printa seperate_key_value
// izmedju svakog elementa se printa seperate_string
// poslije ispisa containera se ispisuje append
template <typename Key, typename T>
void print_container(
  const std::map<Key, T>& container,
  const std::string& seperate_key_value = " -> ",
  const std::string& seperate_string = "\n",
  const std::string& prepend = "",
  const std::string& append = "\n");

// funkcija koja ispisuje container koji je unordered_map
// ciji elemenati imaju kljuc tipa Key i vrijednosti tipa T
// prije ispisa containera se ispisuje prepend
// izmedju kljuca i vrijednosti se printa seperate_key_value
// izmedju svakog elementa se printa seperate_string
// poslije ispisa containera se ispisuje append
template <typename Key, typename T>
void print_container(
  const std::unordered_map<Key, T>& container,
  const std::string& seperate_key_value = " -> ",
  const std::string& seperate_string = "\n",
  const std::string& prepend = "",
  const std::string& append = "\n");

// funkcija koja printa niz elemenata tipa T
template <typename T, size_t N>
void print_container(
  const T (&arr)[N],
  const std::string& seperate_string = " ",
  const std::string& prepend = "",
  const std::string& append = "\n");

// funkcija koja printa container koji je niz elemenata tipa T
// koristeci pointer na pocetak niza i njegovu velicinu kao parametre
template <typename T>
void print_container(
  const T* begin,
  const size_t size,
  const std::string& seperate_string = " ",
  const std::string& prepend = "",
  const std::string& append = "\n");

// funkcija koja printa container koji je niz elemenata tipa T
// koristeci pointer na pocetak i pointer na kraj niza kao parametre
template <typename T>
void print_container(
  const T* begin,
  const T* end,
  const std::string& seperate_string = " ",
  const std::string& prepend = "",
  const std::string& append = "\n");

// ################
// #              #
// #  DEFINICIJE  #
// #              #
// ################

std::vector<int> random_vector_int(const unsigned int& n_element, const int& n_start, const int& n_end)
{
  srand(rand() ^ (unsigned)time(NULL));
  std::vector<int> vec;
  vec.reserve(n_element);

  for (int i = 0; i < n_element; ++i)
    vec.push_back(rand() % (n_end - n_start + 1) + n_start);

  return vec;
}

std::vector<int> ordered_vector_int(const unsigned int& n_element, const int& n_start, const int& n_inc)
{
  std::vector<int> vec;
  vec.reserve(n_element);

  for (int i = 0; i < n_element; ++i)
    vec.push_back(i * n_inc + n_start);

  return vec;
}

std::list<int> random_list_int(const unsigned int& n_element, const int& n_start, const int& n_end)
{
  srand(rand() ^ (unsigned)time(NULL));
  std::list<int> list;

  for (int i = 0; i < n_element; ++i)
    list.push_back(rand() % (n_end - n_start + 1) + n_start);

  return list;
}

std::list<int> ordered_list_int(const unsigned int& n_element, const int& n_start, const int& n_inc)
{
  std::list<int> list;

  for (int i = 0; i < n_element; ++i)
    list.push_back(i * n_inc + n_start);

  return list;
}

std::map<std::string, int> ordered_map_string_int(
  const unsigned int& n_element,
  const std::string& prefix,
  const int& n_start,
  const int& n_inc)
{
  std::map<std::string, int> map;

  for (int i = 0; i < n_element; ++i)
  {
    int val = i * n_inc + n_start;
    map[prefix + std::to_string(val)] = val;
  }

  return map;
}

int* ordered_array_int(const unsigned int& n_element, const int& n_start, const int& n_inc)
{
  int* arr = new int[n_element];

  for (int i = 0; i < n_element; ++i)
    arr[i] = i * n_inc + n_start;

  return arr;
}

int* random_array_int(const unsigned int& n_element, const int& n_start, const int& n_end)
{
  srand(rand() ^ (unsigned)time(NULL));
  int* arr = new int[n_element];

  for (int i = 0; i < n_element; ++i)
    arr[i] = rand() % (n_end - n_start + 1) + n_start;

  return arr;
}

template <typename T>
void print_container(
  const std::vector<T>& container,
  const std::string& seperate_string,
  const std::string& prepend,
  const std::string& append)
{
  auto it = container.begin();
  auto end = container.end();

  if (it == end) return;

  --end;

  std::cout << prepend;
  while (it != end)
    std::cout << *it++ << seperate_string;

  std::cout << *it << append;
}

template <typename T>
void print_container(
  const std::list<T>& container,
  const std::string& seperate_string,
  const std::string& prepend,
  const std::string& append)
{
  auto it = container.begin();
  auto end = container.end();

  if (it == end) return;

  --end;

  std::cout << prepend;
  while (it != end)
    std::cout << *it++ << seperate_string;

  std::cout << *it << append;
}

template <typename Key, typename T>
void print_container(
  const std::map<Key, T>& container,
  const std::string& seperate_key_value,
  const std::string& seperate_string,
  const std::string& prepend,
  const std::string& append)
{
  auto it = container.begin();
  auto end = container.end();

  if (it == end) return;

  --end;

  std::cout << prepend;
  while (it != end)
  {
    std::cout << it->first << seperate_key_value << it->second << seperate_string;
    ++it;
  }

  std::cout << it->first << seperate_key_value << it->second << append;
}

template <typename Key, typename T>
void print_container(
  const std::unordered_map<Key, T>& container,
  const std::string& seperate_key_value,
  const std::string& seperate_string,
  const std::string& prepend,
  const std::string& append)
{
  auto it = container.begin();
  auto end = container.end();

  if (it == end) return;

  --end;

  std::cout << prepend;
  while (it != end)
  {
    std::cout << it->first << seperate_key_value << it->second << seperate_string;
    ++it;
  }

  std::cout << it->first << seperate_key_value << it->second << append;
}

template <typename T, size_t N>
void print_container(
  const T (&arr)[N],
  const std::string& seperate_string,
  const std::string& prepend,
  const std::string& append)
{
  std::cout << prepend;
  for (size_t i = 0; i < N; ++i)
    std::cout << arr[i] << seperate_string;
  std::cout << append;
}

template <typename T>
void print_container(
  const T* begin,
  const size_t size,
  const std::string& seperate_string,
  const std::string& prepend,
  const std::string& append)
{
  std::cout << prepend;
  for (size_t i = 0; i < size; ++i)
    std::cout << begin[i] << seperate_string;
  std::cout << append;
}

template <typename T>
void print_container(
  const T* begin,
  const T* end,
  const std::string& seperate_string,
  const std::string& prepend,
  const std::string& append)
{
  if (begin == end) return;

  --end;

  std::cout << prepend;
  while (begin != end)
    std::cout << *begin++ << seperate_string;

  std::cout << *begin << append;
}
