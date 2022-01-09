// The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

#include <iostream>

int main() 
{
    unsigned long long n = 0;
    unsigned long long num = 10000000000;
    for (int i = 1; i <= 1000; ++i) {
        unsigned long long b = i;
        for (int j = 1; j < i; ++j) {
            b *= i;
            b %= num;
        }
        n += b;
    }
    std::cout << n % num << std::endl;

    return 0;
}