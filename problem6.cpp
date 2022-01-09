// The sum of the squares of the first ten natural numbers is 385.
// The square of the sum of the first ten natural numbers is 3025.
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 2640 .
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>

int main()
{
    int sum_square {} ;
    int square_sum {} ;
    for(int i = 0; i <= 100 ; ++i )
    {
        square_sum += i * i ;
        sum_square += i ;
    }
    sum_square *= sum_square ;
    std::cout << sum_square - square_sum << std::endl ;
    return 0;
}