// The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8,
// which is correct, is obtained by cancelling the 9s.
// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
// There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
// If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

#include <iostream>

int foo(int a, int b) {
    if (a < b) {
        int c = a;
        a = b;
        b = c;
    }
    while (b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n = 1;
    int d = 1;
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            for (int k = 1; k < j; ++k)
            {
                if ((k * 10 + i) * j == k * (i * 10 + j)) {
                    n *= (k * 10 + i);
                    d *= (i * 10 + j);
                }
            }
        }
    }

    std::cout << d / foo(n, d) << std::endl;
    return 0;
}