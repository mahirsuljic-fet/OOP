#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// #include "MojNizInt.hpp"
//
// WARNING: When start implementing test below, comment last test in test1.cpp
// since it won't be valid anymore!!!
TEST_CASE(
    "SECOND_PUSH_BACK_Expects push_back to append element at the end of "
    "array") {
  MojNizInt mojNiz;
  CHECK_EQ(mojNiz.capacity(), 1);
  mojNiz.push_back(5);
  CHECK_EQ(mojNiz.size(), 1);
  CHECK_EQ(mojNiz.at(0), 5);
  auto addr51 = &mojNiz[0];  // taking address of 5 just after first push_back
  CHECK_EQ(mojNiz.capacity(), 1);  // capacity should still be 1

  mojNiz.push_back(7);
  CHECK_EQ(mojNiz.size(), 2);
  CHECK_EQ(mojNiz.at(1), 7);
  auto addr52 = &mojNiz[0];  // taking address of 5 after push_back of 7
  CHECK_NE(addr52, addr51);  // addresses should be different since reallocation
                             // should happen at this point

  CHECK_EQ(mojNiz.capacity(), 2);  // extending capacity to two now

  mojNiz.push_back(9);
  CHECK_EQ(mojNiz.size(), 3);
  CHECK_EQ(mojNiz.at(2), 9);
  auto addr53 = &mojNiz[0];  // taking address of 5 after push_back of 9
  CHECK_NE(addr52, addr53);  // addresses should be different since reallocation
                             // should happen at this point
  CHECK_NE(addr52, addr51);  // addresses should be different since reallocation
                             // should happen at this point

  CHECK_EQ(mojNiz.capacity(), 4);  // extending capacity to four

  mojNiz.push_back(11);
  CHECK_EQ(mojNiz.size(), 4);
  CHECK_EQ(mojNiz.at(2), 9);
  auto addr54 = &mojNiz[0];  // taking address of 5 after push_back of 9
  CHECK_EQ(addr53, addr54);  // addresses should be the same since reallocation
                             // should not happen now

  CHECK_EQ(mojNiz.capacity(), 4);  // capacity remains the same
}

TEST_CASE(
    "Expects that capacity is properly managed in copy ctor and copy "
    "operator=") {
  MojNizInt mojNiz{1, 2, 3, 4};
  for (auto i = 0; i < 20; ++i) {
    mojNiz.push_back(i);
  }

  // checking that capacity is copied properly through copy ctor
  MojNizInt mojNiz2 = mojNiz;
  for (auto i = 0; i < 700; ++i) {
    mojNiz2.push_back(i);
  }
  for (auto i = 0; i < 700; ++i) {
    CHECK_EQ(mojNiz2[i + 24], i);
  }

  // checking that capacity is copied properly through copy operator=
  MojNizInt mojNiz3;
  mojNiz3 = mojNiz;
  for (auto i = 0; i < 700; ++i) {
    mojNiz3.push_back(i);
  }
  for (auto i = 0; i < 700; ++i) {
    CHECK_EQ(mojNiz3[i + 24], i);
  }
}

TEST_CASE(
    "Expects that capacity is properly managed in move ctor and move "
    "operator=") {
  MojNizInt mojNiz{1, 2, 3, 4};
  for (auto i = 0; i < 20; ++i) {
    mojNiz.push_back(i);
  }

  // checking that capacity is copied properly through move ctor
  MojNizInt mojNiz2 = std::move(mojNiz);
  for (auto i = 0; i < 700; ++i) {
    mojNiz2.push_back(i);
  }
  for (auto i = 0; i < 700; ++i) {
    CHECK_EQ(mojNiz2[i + 24], i);
  }

  MojNizInt mojNiz3{1, 2, 3, 4};
  for (auto i = 0; i < 20; ++i) {
    mojNiz3.push_back(i);
  }

  // checking that capacity is copied properly through copy operator=
  MojNizInt mojNiz4;
  mojNiz4 = std::move(mojNiz3);
  for (auto i = 0; i < 700; ++i) {
    mojNiz4.push_back(i);
  }
  for (auto i = 0; i < 700; ++i) {
    CHECK_EQ(mojNiz4[i + 24], i);
  }
}

TEST_CASE("Expects to implement pop_back, back and front methods") {
  MojNizInt mojNiz;
  CHECK_EQ(mojNiz.capacity(), 1);
  mojNiz.push_back(5);
  CHECK_EQ(mojNiz.size(), 1);
  CHECK_EQ(mojNiz.back(), 5);
  CHECK_EQ(mojNiz.front(), 5);
  auto addr51 = &mojNiz[0];  // taking address of 5 just after first push_back
  CHECK_EQ(mojNiz.capacity(), 1);  // capacity should still be 1

  mojNiz.push_back(7);
  CHECK_EQ(mojNiz.size(), 2);
  CHECK_EQ(mojNiz.at(1), 7);
  CHECK_EQ(mojNiz.front(), 5);
  CHECK_EQ(mojNiz.back(), 7);
  auto addr52 = &mojNiz[0];  // taking address of 5 after push_back of 7
  CHECK_NE(addr52, addr51);  // addresses should be different since reallocation
                             // should happen at this point

  CHECK_EQ(mojNiz.capacity(), 2);  // extending capacity to two now

  mojNiz.push_back(9);
  CHECK_EQ(mojNiz.size(), 3);
  CHECK_EQ(mojNiz.front(), 5);
  CHECK_EQ(mojNiz.back(), 9);
  auto addr53 = &mojNiz[0];  // taking address of 5 after push_back of 9
  CHECK_NE(addr52, addr53);  // addresses should be different since reallocation
                             // should happen at this point
  CHECK_NE(addr52, addr51);  // addresses should be different since reallocation
                             // should happen at this point

  CHECK_EQ(mojNiz.capacity(), 4);  // extending capacity to four

  mojNiz.pop_back();
  CHECK_EQ(mojNiz.size(), 2);
  CHECK_EQ(mojNiz.front(), 5);
  CHECK_EQ(mojNiz.back(), 7);
  auto addr54 = &mojNiz[0];  // taking address of 5 after push_back of 9
  CHECK_EQ(addr54, addr53);  // addresses should be the same since pop_back
                             // should never reallocate
  CHECK_EQ(mojNiz.capacity(), 4);  // pop_back does not change capacity

  mojNiz.pop_back();
  CHECK_EQ(mojNiz.size(), 1);
  CHECK_EQ(mojNiz.front(), 5);
  CHECK_EQ(mojNiz.back(), 5);
  auto addr55 = &mojNiz[0];  // taking address of 5 after push_back of 9
  CHECK_EQ(addr55, addr54);  // addresses should be the same since pop_back
                             // should never reallocate
  CHECK_EQ(addr55, addr53);  // addresses should be the same since pop_back
                             // should never reallocate
  CHECK_EQ(mojNiz.capacity(), 4);  // pop_back does not change capacity

  mojNiz.push_back(19);
  CHECK_EQ(mojNiz.size(), 2);
  CHECK_EQ(mojNiz.front(), 5);
  CHECK_EQ(mojNiz.back(), 19);
  auto addr56 = &mojNiz[0];  // taking address of 5 after push_back of 9
  CHECK_EQ(addr56, addr55);  // addresses should be the same since pop_back
                             // should never reallocate
  CHECK_EQ(addr56, addr54);  // addresses should be the same since pop_back
                             // should never reallocate
  CHECK_EQ(addr56, addr53);  // addresses should be the same since pop_back
                             // should never reallocate
  CHECK_EQ(mojNiz.capacity(), 4);  // pop_back does not change capacity
}

