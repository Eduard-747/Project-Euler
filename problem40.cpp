// An irrational decimal fraction is created by concatenating the positive integers:
// 0.123456789101112131415161718192021...
// It can be seen that the 12th digit of the fractional part is 1.
// If dn represents the nth digit of the fractional part, find the value of the following expression.

#include <iostream>
#include <cmath>

int main() 
{
    std::string n;
    for (int i = 0; i < 1000000; ++i) 
    {
        n.append(std::to_string(i));
    }

    int product = 1;
    for (int i = 0; i < 7; ++i) 
    {
        product *= n[std::pow(10, i)] - 48;
    }

    std::cout << product << std::endl;

    return 0;
}