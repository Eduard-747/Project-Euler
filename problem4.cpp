// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <algorithm>
#include <iostream>

bool is_palindrome(const int& number) {
    int copy = number;
    int reversed = 0;

    while (copy > 0) {
        reversed *= 10;
        reversed += copy % 10;
        copy /= 10;
    }

    return reversed == number ;
}

int main() 
{
    int max_product = 0 ;

    for (int i = 999; i > 99 ; --i) {
        for (int j = 999; j > 99 ; --j) {
            int product = i * j ;

            if (is_palindrome(product)) {
                max_product = std::max(product, max_product);
                break ;
            }
        }
    }

    std::cout << max_product << std::endl ;
    return 0;
}