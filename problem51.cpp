// By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
// By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers,
// yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family,is the smallest prime with this property.
// Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.

#include <iostream>
#include <cmath>
#include <algorithm>

bool isPrime(const int& n) 
{
    if (n <= 1) {
        return false;
    }
    else if (n == 2) {
        return true;
    }
    else if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int check(const std::string& s) 
{
    int count = 0;
    for (unsigned char i = '0'; i <= '9'; ++i) {
        if (i == '0' && s[0] == '1') {
            continue;
        }
        std::string q = s;
        for (char &c : q) {
            if (c == '1') {
                c = i;
            }
        }
        count += isPrime(std::stoi(q));
    }
    return count;
}

int main() 
{
    int n = 1;
    while (true) {
        for (int i = 1; i < 1000; i += 2) {
            if (i % 5 == 0) {
                continue;
            }
            std::string s = std::string(n, '1') + std::to_string(i);
            std::sort(s.begin(), s.end());
            do {
                if (check(s) == 8) {
                    std::cout << s << std::endl;
                    return 0;
                }
            } while (std::next_permutation(s.begin(), s.end()));
        }
        ++n;
    }
}