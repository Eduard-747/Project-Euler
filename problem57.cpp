#include <iostream>

int countDigits(u_long n) 
{
    int count = 0;
    while (n) 
    {
        ++count;
        n /= 10;
    }
    return count;
}

int main()
{
	int ans = 0;
	u_long n = 1 ;
    u_long d = 2;
	for (int i = 0; i < 1000; i++) {
		if (countDigits(n+d) > countDigits(d)) ans++;
		n += d+d;
		std::swap(n,d);
		if (n > (1ULL<<61)) {
			n /= 10;
			d /= 10;
		}
	}
	std::cout << ans << "\n";
    return 0;
}