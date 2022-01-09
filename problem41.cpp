// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
// What is the largest n-digit pandigital prime that exists?

#include <iostream>
#include <algorithm>
#include <cmath>

bool isPrime(int n) 
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
    for (int i = 3; i <= n / 2; i += 2) 
    {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() 
{
    std::string validDigits = "1234567";
    int largestPandigitalPrime = 0;

    do {
        int n = std::stoi(validDigits);
        if (isPrime(n) && n > largestPandigitalPrime) {
            largestPandigitalPrime = n;
        }
    } while (std::next_permutation(validDigits.begin(), validDigits.end()));

    std::cout << largestPandigitalPrime << std::endl;

    return 0;
}