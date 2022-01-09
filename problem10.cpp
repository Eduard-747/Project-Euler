// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

#include <iostream>

bool is_prime(int n) {
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

int main()
{
    int sum {} ;
    for(int i = 2; i < 2000000; ++i)
    {
        if(is_prime(i)) {
            sum += i ;
        }
    }
    std::cout << sum << std::endl ;
    return 0;
}