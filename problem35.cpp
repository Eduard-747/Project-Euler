// The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
// There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
// How many circular primes are there below one million?

#include <iostream>
#include <cmath>

int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int countDigits(int n)
{
    int count {};
    while(n)
    {
        ++count;
        n /= 10;
    }
    return count;
}


int main()
{
    int i, j, a, b, cnt, cnt2, digitnumber, result = 0;

    for (i = 2; i < 1000000; i++)
    {
        cnt = 0;
        for (j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0) {
                cnt++;
                break;
            }
        }
        if (cnt != 0) {
            continue;
        }
        if (i < 10 && cnt == 0) {
            result++;
            continue;
        }
        digitnumber = countDigits(i);
        int numbers[digitnumber];
        numbers[0] = i;
        for (b = 1; b < digitnumber; b++)
        {
            numbers[b] = 0;
        }
        for (a = 1; a < digitnumber; a++)
        {
            cnt2 = 0;
            int digits[digitnumber];
            for (j = digitnumber; j > 0; j--)
            {
                digits[j - 1] = (numbers[a - 1] % power(10, j)) / (power(10, (j - 1)));
            }
            int tmp [digitnumber];
            tmp[a - 1] = digits[digitnumber - 1];
            for (j = digitnumber; j > 0; j--)
            {
                digits[j - 1] = digits[j - 2];
                if (j == 1) {
                    digits[j - 1] = tmp[a - 1];
                }
            }
            for (j = digitnumber; j > 0; j--)
            {
                numbers[a] += (digits[j - 1] * power(10, (j - 1)));
            }
            for (j = 2; j <= sqrt(numbers[a]); j++)
            {
                if (numbers[a] % j == 0) {
                    cnt2++;
                    break;
                }
            }
            if (cnt2 != 0) {
                break;
            }
            if (a == (digitnumber - 1)) {
                result++;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}