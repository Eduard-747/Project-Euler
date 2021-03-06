// Consider all integer combinations of ab for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:
// 22=4, 23=8, 24=16, 25=32
// 32=9, 33=27, 34=81, 35=243
// 42=16, 43=64, 44=256, 45=1024
// 52=25, 53=125, 54=625, 55=3125
// If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:
// 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125
// How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?

#include <iostream>

int powOf(const int& n)
{
	for (int i = 2; i*i <= n; i++)
    {
		if (n % i == 0) {
			int pow = 0, temp = n;
			for (; temp % i == 0; temp /= i, pow++);
			if (temp == 1) return pow;
		}
	}
	return 1;
}

int main()
{
    const int N = 100 ;
	int overlap[6 + 1] = {0};
	bool used[6 * N + 1] = {0};
	for (int pow = 1; pow < 6 + 1; pow++) {
		for (int b = 2 * pow; b <= N * pow; b += pow) {
			if (used[b]) overlap[pow]++;
			used[b] = 1;
		}
	}
	int sum = 0;
	for (int a = 2; a <= N; a++)
		sum += N - 1 - overlap[powOf(a)];
	std::cout << sum << "\n";
}