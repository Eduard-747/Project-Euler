// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23 .
// Find the sum of all the multiples of 3 or 5 below n .

#include <iostream>

namespace consts
{
    const int multiples_3 = 3 ;
    const int multiples_5 = 5 ;
}

int return_sum(const int& n)
{
    int sum{} ;
    for(int i = 0 ; i < n ; i += consts::multiples_3) 
    {
        sum += i ;
    }
    for(int i = 0 ; i < n ; i += consts::multiples_5) 
    {
        sum += i ;
    }
    return sum ;
}

int main()
{
    int n ;
    std::cout << "Enter n: " ;
    std::cin >> n ;
    std::cout << "The sum of these multiples is " << return_sum(n) << std::endl ;
    return 0 ;
}