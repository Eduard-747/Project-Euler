#include <iostream>

bool is_prime(const int& n) {
    if (n <= 1) {
        return false;
    }
    else if (n == 2) {
        return true;
    }
    else if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= n / 2; i += 2)
    {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int productAB;
    int largestN = 0;

    for (int a = -999; a < 1000; ++a)
    {
        for (int b = -1000; b <= 1000; ++b)
        {
            int n = 0;
            bool consecutive = true;
            while (consecutive)
            {
                ++n;
                if (!is_prime(n*n + a*n + b)) {
                    consecutive = false;
                    if (n > largestN) {
                        largestN = n;
                        productAB = a * b;
                    }
                }
            }
        }
    }
    std::cout << productAB << std::endl;
    return 0;
}