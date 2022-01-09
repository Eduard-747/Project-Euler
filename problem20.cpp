// n! means n × (n − 1) × ... × 3 × 2 × 1
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
// Find the sum of the digits in the number 100!

#include <iostream>
#include <vector>

std::vector<int> BigNumFactorial(const int& n) 
{
    std::vector<int> vec {1};
    for (int i = 2; i <= n; ++i)
    {
        for (auto & it : vec) {
            it *= i;
        }
        for (int j = 0; j < vec.size(); ++j)
        {
            if (vec[j] >= 10) {
                if (j+1 != vec.size()) {
                    vec[j + 1] += (vec[j] - (vec[j] % 10)) / 10;
                }
                else {
                    vec.push_back((vec[j] - (vec[j] % 10)) / 10);
                }
                vec[j] = vec[j] % 10;
            }
        }
    }
    return vec;
}

int main() 
{

    int sum = 0;
    std::vector<int> vec = BigNumFactorial(100);

    for (auto &it : vec) {
        sum += it;
    }

    std::cout << sum << std::endl;

    return 0;
}