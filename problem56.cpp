// A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: 
// one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
// Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?

#include <iostream>

int main()
{
	int maxSum = 0;
	for (int i = 99; i >= 90; --i) 
    {
		short d[200] = {0};
		d[0] = 1;
		int l = 1;
		for (int j = 0; j < 99; ++j) 
        {
			for (int dig = 0; dig < l; dig++) {
                d[dig] *= i;
            }
			for (int dig = 0; dig <= l; dig++) {
				if (d[dig] && dig == l) l++;
				d[dig+1] += d[dig] / 10;
				d[dig] %= 10;
			}
			if (j > 89) {
				int sum = 0;
				for (int k = 0; k < l; k++) 
                {
                    sum += d[k];
                }
				if (sum > maxSum) {
                    maxSum = sum;
                }
			}
		}
	}
	std::cout << maxSum << std::endl;
    return 0;
}