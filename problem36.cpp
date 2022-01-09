// The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
// (Please note that the palindromic number, in either base, may not include leading zeros.)

#include <iostream>

int toPal(int n, bool even)
{
	if (even)
		n = n * 10 + n % 10;
	for (int tempN = (even ? n / 100: n / 10); tempN > 0; tempN /= 10)
		n = n * 10 + tempN % 10;
	return n;
}

bool base2Pal(int n)
{
	int reversedN = 0;
	for (int power = 0; n >= 1 << power; power++)
		reversedN = reversedN * 2 + ((n & (1 << power)) ? 1 : 0);
	return reversedN == n;
}

int main()
{
	int sum = 0;
	for (int n = 0; n < 1000; n++) 
    {
		int pal1 = toPal(n, false);
		int pal2 = toPal(n, true);
		if (base2Pal(pal1))
			sum += pal1;
		if (base2Pal(pal2))
			sum += pal2;
	}
	std::cout << sum << std::endl;
    return 0;
}
