// It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
// 9 = 7 + 2×12
// 15 = 7 + 2×22
// 21 = 3 + 2×32
// 25 = 7 + 2×32
// 27 = 19 + 2×22
// 33 = 31 + 2×12
// It turns out that the conjecture was false.
// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

#include <iostream>
#include <cmath>
#include <vector>

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
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> primes;

bool check(const int& n) 
{
    for (int p : primes) {
        int q = 1;
        while (n >= p + 2 * q * q) {
            if (n == p + 2 * q * q) {
                return true;
            }
            ++q;
        }
    }
    return false;
}

int main() 
{

    int n = 2;
    while (true) 
    {
        if (isPrime(n)) {
            primes.push_back(n);
        }
        else if (n % 2 != 0 && !check(n)) {
            break;
        }
        ++n;
    }
    std::cout << n << std::endl;

    return 0;
}