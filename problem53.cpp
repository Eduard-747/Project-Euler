#include <iostream>

double choose(const double& n, const double& r) 
{
	double p = 1;
	for (int i = 1; i <= r; ++i) {
        p *= (n + 1 - i) / i;
    }
	return p;
}

int main() 
{
    int n = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (choose(i, j) > 1000000) {
                ++n;
            }
        }
    }
    std::cout << n << std::endl;
    return 0;
}