// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the n prime number?

#include <iostream>

bool is_prime(const int& num)
{
    for(int i = 2 ; i <= num / 2 ; ++i)
    {
        if(num % i == 0) return false ;
    }
    return true ;
}

int main()
{
    std::cout << "enter n: " ;
    int n ;
    std::cin >> n ;
    for(int i = 3, j = 0 ; ; ++i)
    {
        if(is_prime(i))
        {
            ++j ;
            if(j == n) 
            {
                std::cout << i ;
                break ;
            }
        }
    }
    return 0;
}