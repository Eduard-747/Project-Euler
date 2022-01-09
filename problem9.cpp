// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2
// For example, 32 + 42 = 9 + 16 = 25 = 52.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>

void find_abc()
{
    for(int a = 1; a < 500; ++a)
    {
        for(int b = 1 ; b < 500; ++b)
        {
            for(int c = 1; c < 500; ++c)
            {
                if (a + b + c == 1000) {
                    if((a * a) + (b * b) == (c * c)) {
                        std::cout << a << " " << b << " " << c ;
                        return ;
                    }
                }
            }
        }
    }
    return ;
}

int main()
{
    find_abc() ;
    return 0;
}