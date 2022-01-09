// Take the number 192 and multiply it by each of 1, 2, and 3:
// 192 × 1 = 192
// 192 × 2 = 384
// 192 × 3 = 576
// By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)
// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
// What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

#include <iostream>

bool isPandigital_9(long long n) 
{
    int results = 0;
    while (n > 0) 
    {
        int digit = n % 10;
        if (digit == 0) {
            return false;
        }
        results |= 1 << (digit - 1);
        n /= 10;
    }
    return results == 511;
}

long long concatenateNumbers(long long a, long long b) 
{
    long long c = 1;
    while (c <= b) 
    {
        c *= 10;
    }
    return (a * c) + b;
}

int main()
{

    long long max = 0;
    for (int i = 1; i < 10000; ++i) 
    {
        long long concatenatedProduct = i;
        int n = 2;
        while (concatenatedProduct < 100000000) 
        {
            concatenatedProduct = concatenateNumbers(concatenatedProduct, i * n);
        }
        if (isPandigital_9(concatenatedProduct) && concatenatedProduct > max) {
            max = concatenatedProduct;
        }
    }

    std::cout << max << std::endl;

    return 0;
}