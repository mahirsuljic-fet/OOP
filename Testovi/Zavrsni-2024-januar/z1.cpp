// Navesti bar jednu operaciju koja je nije validna
// za p1 i p2, a jeste validna za p.

int a = 5;
int* p = &a;
const int* p1 = &a;
int const* p2 = &a;

// odgovor

++(*p1);
(*p2)++;
*p1 = 1;
*p2 += 2;
*p1 -= 3;
*p2 *= 4;
*p1 /= 5;
*p2 %= 6;
// itd.
