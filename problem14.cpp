// The following iterative sequence is defined for the set of positive integers:
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
// Using the rule above and starting with 13, we generate the following sequence:
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
// Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
// Which starting number, under n , produces the longest chain?

#include <iostream>

int sequence_cout(int n)
{
    int count {} ;
    while(n != 1)
    {
        ++count ;
        if(n % 2 == 0) {
            n /= 2 ;
        } else {
            n = 3 * n + 1 ;
        }
    }
    return count ;
}

int main()
{
    std::cout << "Enter n:" ;
    int n ;
    std::cin >> n ;
    int max{} ;
    for(int i = 1 ; i < n; ++i) 
    {
        if(sequence_cout(i) > max)
        {
            max = sequence_cout(i) ;
        }
    }
    std::cout << max << std::endl ;
    return 0;
}