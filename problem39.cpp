// If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
// {20,48,52}, {24,45,51}, {30,40,50}
// For which value of p ≤ 1000, is the number of solutions maximised?

#include <iostream>
#include <cmath>

int main() 
{
    int optimalP {};
    int largestNumSolutions {};
    for (int p = 3; p <= 1000; ++p) 
    {
        int numSolutions = 0;
        int a = 1;
        while (a < p / 4) 
        {
            int b = 1;
            while (b < (p - a) / 2) 
            {
                if (p == a + b + std::sqrt(a * a + b * b)) {
                    ++numSolutions;
                }
                ++b;
            }
            ++a;
        }
        if (numSolutions > largestNumSolutions) {
            largestNumSolutions = numSolutions;
            optimalP = p;
        }
    }

    std::cout << optimalP << std::endl;

    return 0;
}