// The first two consecutive numbers to have two distinct prime factors are:
// 14 = 2 × 7
// 15 = 3 × 5
// The first three consecutive numbers to have three distinct prime factors are:
// 644 = 2² × 7 × 23
// 645 = 3 × 5 × 43
// 646 = 2 × 17 × 19.
// Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

#include <iostream>
#include <set>

std::set<int> getDistinctPrimeFactors(int n) 
{
    std::set<int> distinctPrimeFactors;
    while (n > 1) 
    {
        for (int i = 2; i <= n; ++i) 
        {
            if (n % i == 0) {
                distinctPrimeFactors.insert(i);
                n /= i;
                --i;
            }
        }
    }
    return distinctPrimeFactors;
}

int main() 
{

    int numConsecutiveValidValues = 0;
    int n = 0;
    while (numConsecutiveValidValues != 4) 
    {
        if (getDistinctPrimeFactors(n).size() == 4) {
            ++numConsecutiveValidValues;
        }
        else {
            numConsecutiveValidValues = 0;
        }
        ++n;
    }

    std::cout << n - 4 << std::endl;

    return 0;
}