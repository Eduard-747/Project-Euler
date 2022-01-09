// Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
// As 1 = 1^4 is not a sum it is not included.
// The sum of these numbers is 1634 + 8208 + 9474 = 19316.
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

#include <iostream>
#include <cmath>

int main() 
{
    int sum = 0;
    int n = 1;
    int limit = 6 * 59049 ;
    while (n < limit) 
    {
        ++n;
        int digitSum = 0;
        int q = n;
        while (q != 0) 
        {
            digitSum += std::pow(q % 10, 5);
            q /= 10;
        }
        if (digitSum == n) {
            sum += n;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}