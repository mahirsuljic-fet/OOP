#pragma once

#include <string>

struct radnik
{
    std::string ime;
    int starost;
    double plata;
};

bool poImenu(const radnik&, const radnik&);
bool poPlati(const radnik& a, const radnik& b);
