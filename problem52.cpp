// It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

#include <iostream>

bool isPermutation(int a, int b) 
{
    int c[10] = {0};
    while (a > 0) {
        ++c[a % 10];
        a /=10;
    }
    while (b > 0) {
        --c[b % 10];
        b /= 10;
    }
    bool permutation = true;
    for (int i = 0; i < 10; ++i) {
        permutation &= !c[i];
    }
    return permutation;
}

int main() 
{

    int n = 1;
    while (true) {
        int i;
        for (i = 2; i <= 6; ++i) {
            if (!isPermutation(n, i * n)) {
                break;
            }
        }
        if (i == 7) {
            break;
        }
        ++n;
    }

    std::cout << n << std::endl;

    return 0;
}