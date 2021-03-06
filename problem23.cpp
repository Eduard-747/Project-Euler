// A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
// For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
// A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
// By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
// However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as
// the sum of two abundant numbers is less than this limit.
// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

#include <iostream>
#include <vector>

int sumProperDivisors(const int& n) 
{
    int sum {1};
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() 
{

    int limit = 28123;
    std::vector<int> abundants;
    for (int i = 1; i < limit; ++i)
    {
        if (sumProperDivisors(i) > i) {
            abundants.push_back(i);
        }
    }

    bool isSumOfAbundants[limit];
    for(int i = 0; i < abundants.size(); ++i)
    {
        for (int j = i; j < abundants.size(); ++j)
        {
            if (abundants[i] + abundants[j] < limit) {
                isSumOfAbundants[abundants[i] + abundants[j]] = true;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < limit; ++i)
    {
        if (!isSumOfAbundants[i]) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}