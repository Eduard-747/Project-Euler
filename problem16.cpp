// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?
  
#include <iostream>
#include <vector>

std::vector<int> foo(const int& n) 
{
    std::vector<int> vec {1} ;
    for (int i = 0; i < n; ++i) 
    {
        for (auto &it : vec) {
            it *= 2;
        }
        for (int j = 0; j < vec.size(); ++j) 
        {
            if (vec[j] >= 10) {
                if (j + 1 != vec.size()) {
                    vec[j+1] += (vec[j] - (vec[j] % 10)) / 10;
                }
                else {
                    vec.push_back((vec[j] - (vec[j] % 10)) / 10);
                }
                vec[j] %= 10;
            }
        }
    }
    return vec;
}


int main() {

    int sum = 0;
    std::vector<int> vec = foo(1000);

    for (auto &it : vec) {
        sum += it;
    }

	std::cout << sum << std::endl;
    return 0;
}
