// A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
// 1/2	= 	0.5
// 1/3	= 	0.(3)
// 1/4	= 	0.25
// 1/5	= 	0.2
// 1/6	= 	0.1(6)
// 1/7	= 	0.(142857)
// 1/8	= 	0.125
// 1/9	= 	0.(1)
// 1/10	= 	0.1
// Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
// Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> primeSieve(const int& n) 
{
    std::vector<int> result;
    if (n < 2) {
        return result;
    }
    std::vector<bool> input(n + 1, true);
    const int limit = (int) (std::floor(std::sqrt(n)) + 1);
    for (int i = 2; i <= limit; ++i)
    {
        if (!input[i]) {
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            input[j] = false;
        }
    }
    result.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (input[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int main() 
{
    int longestCycleLength = 0;
    int longestCycleNumber = 0;

    for (int i : primeSieve(1000))
    {
        if (i == 2 || i == 5) {
            continue;
        }
        int cycleLength = 1;
        int j = 10;
        while (j % i != 1)
        {
            ++cycleLength;
            j *= 10;
            j %= i;
        }
        if (cycleLength > longestCycleLength) {
            longestCycleLength = cycleLength;
            longestCycleNumber = i;
        }
    }

    std::cout << longestCycleNumber << std::endl;

    return 0;
}