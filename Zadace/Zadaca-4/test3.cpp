#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// #include "MojNiz.hpp"

TEST_CASE("Expects to construct MojNiz from MojNiz of different inner type") {
  MojNiz<double> mojNiz1{1.1, 1.6, 2.7, 2.9};
  for (auto i = 0; i < 20; ++i) {
    mojNiz1.push_back(i + 0.);
  }
  MojNiz<int> mojNiz2 = mojNiz1;

  CHECK_EQ(mojNiz1.size(), 24);
  CHECK_EQ(mojNiz1[0], 1.1);
  CHECK_EQ(mojNiz1[1], 1.6);
  CHECK_EQ(mojNiz1[2], 2.7);
  CHECK_EQ(mojNiz1[3], 2.9);

  CHECK_EQ(mojNiz2.size(), 24);
  CHECK_EQ(mojNiz2[0], 1);
  CHECK_EQ(mojNiz2[1], 1);
  CHECK_EQ(mojNiz2[2], 2);
  CHECK_EQ(mojNiz2[3], 2);

  for (auto i = 0; i < 700; ++i) {
    mojNiz2.push_back(i);
  }
  for (auto i = 0; i < 700; ++i) {
    CHECK_EQ(mojNiz2[i + 24], i);
  }
}

TEST_CASE(
    "Expects to have a copy operator= with MojNiz of different inner type") {
  MojNiz<double> mojNiz1{0.9, 2.1, 4.7, 6.5, 8.9};
  MojNiz<int> mojNiz2;
  for (auto i = 0; i < 20; ++i) {
    mojNiz1.push_back(i + 0.);
  }

  // Did you replace the size?
  mojNiz2 = mojNiz1;
  CHECK_EQ(mojNiz2.size(), 25);
  for (auto i = 0; i < 5; ++i) {
    CHECK_EQ(mojNiz2[i], 2 * i);
  }
  CHECK_EQ(mojNiz1[0], 0.9);
  CHECK_EQ(mojNiz1[1], 2.1);
  CHECK_EQ(mojNiz1[2], 4.7);
  CHECK_EQ(mojNiz1[3], 6.5);
  CHECK_EQ(mojNiz1[4], 8.9);

  for (auto i = 0; i < 1500; ++i) {
    mojNiz1.push_back(i);
  }
  for (auto i = 0; i < 1500; ++i) {
    CHECK_EQ(mojNiz1[i + 25], i);
  }
}

TEST_CASE("Expects to have operator+ with MojNiz of different inner type") {
  MojNiz<double> mojNiz1{1.1, 2.1, 3.1, 4.1, 5.1};
  MojNiz<int> mojNiz2{0, 1, 2, 3};

  CHECK_THROWS_AS(mojNiz1 + mojNiz2, std::invalid_argument);
  CHECK_THROWS_AS(mojNiz2 + mojNiz1, std::invalid_argument);

  mojNiz2.push_back(4);

  auto sumChecker = [&](const MojNiz<double>& sum) {
    for (auto i = 0; i < mojNiz1.size(); ++i) {
      CHECK_EQ(mojNiz1[i], i + 1.1);
    }
    for (auto i = 0; i < mojNiz2.size(); ++i) {
      CHECK_EQ(mojNiz2[i], i);
    }
    for (auto i = 0; i < sum.size(); ++i) {
      CHECK_EQ(sum[i], (double)i * 2 + 1.1);
    }
  };

  // expects to always return MojNiz with bigger inner type
  auto sum1 = mojNiz1 + mojNiz2;
  auto sum2 = mojNiz2 + mojNiz1;
  CHECK_EQ(std::is_same<MojNiz<double>, decltype(sum1)>::value, true);
  CHECK_EQ(std::is_same<MojNiz<double>, decltype(sum2)>::value, true);

  sumChecker(sum1);
  sumChecker(sum2);
}
