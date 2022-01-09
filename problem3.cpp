// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number n ?

#include<iostream>

long long largest_prime_factor(const long long& n)
{
    if (n % 2 == 0) return n / 2 ;

    int i ;
    for(i = 3; i * i <= n; ++i) 
    {
        if (n % i == 0) break ;
    }
    if (i * i <= n) return n / i ;

    return -1 ;
}

int main() 
{
    long long n;
    std::cout << "Enter n: " ;
    std::cin >> n;
    std::cout << "largest prime factor " << largest_prime_factor(n) << std::endl ;
    return 0 ;
}