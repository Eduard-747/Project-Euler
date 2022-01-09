// The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: 
// (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
// There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
// What 12-digit number do you form by concatenating the three terms in this sequence?

#include <iostream>
#include <cmath>

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

bool isPermutation(int a, int b) 
{
    int c[10] = {0};
    while (a > 0) {
        ++c[a % 10];
        a /=10;
    }
    while (b > 0) {
        --c[b % 10];
        b /= 10;
    }
    bool permutation = true;
    for (int i = 0; i < 10; ++i) {
        permutation &= !c[i];
    }
    return permutation;
}

int main() 
{

    for (int i = 1000; i < 3340; ++i) {
        if (isPrime(i) && isPrime(i + 3330) && isPrime(i + 2 * 3330) && isPermutation(i, i + 3330) && isPermutation(i , i + 2 * 3330) && i != 1487) {
            std::cout << std::to_string(i) + std::to_string(i + 3330) + std::to_string(i + 2 * 3330) << std::endl;
            break;
        }
    }

    return 0;
}