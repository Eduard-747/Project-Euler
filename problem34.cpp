// 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
// Find the sum of all numbers which are equal to the sum of the factorial of their digits.
// Note: As 1! = 1 and 2! = 2 are not sums they are not included.

#include <iostream>

int main()
{
	int factorial[10] = {1};
	for (int n = 1; n < 10; n++)
	{
        factorial[n] = factorial[n - 1] * n;
    }
	int toSum = 0;
	for (int n = 10; n < 2540160; n++) 
    {
		int tempN = n, sum = 0;
		for (; tempN > 0; sum += factorial[tempN % 10], tempN /= 10);
		if (sum == n) toSum += n;
	}
	std::cout << toSum << std::endl;
    return 0;
}