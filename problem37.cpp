// The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right,
// and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

#include <iostream>
#include <cmath>

int countDigits(int n) 
{
    int count = 0;
    while (n) 
    {
        ++count;
        n /= 10;
    }
    return count;
}

int getLeftmostDigit(const int& n) 
{
    int leftmostDigit = n;
    while (true) 
    {
        if (leftmostDigit % 10 == leftmostDigit) {
            return leftmostDigit;
        }
        leftmostDigit /= 10;
    }
    return 0;
}

bool isPrime(const int& n) 
{
    if (n <= 1) {
        return false;
    }
    else if (n == 2) {
        return true;
    }
    else if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= n / 2; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isTruncatablePrimeRight(int n) 
{
    while (n > 0) 
    {
        if (!isPrime(n)) {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool isTruncatablePrimeLeft(int n) 
{
    while (n > 0) 
    {
        if (!isPrime(n)) {
            return false;
        }
        n -= getLeftmostDigit(n) * std::pow(10, countDigits(n) - 1);
    }
    return true;
}

bool isTruncatablePrime(int n) 
{
    return isTruncatablePrimeLeft(n) && isTruncatablePrimeRight(n);
}

int main() 
{
    int sum = 0;
    int numFound = 0;
    int n = 10;
    while (numFound < 11) 
    {
        if (isTruncatablePrime(n)) {
            sum += n;
            ++numFound;
        }
        ++n;
    }

    std::cout << sum << std::endl;

    return 0;
}