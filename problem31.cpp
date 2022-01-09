// In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
// It is possible to make £2 in the following way:
// 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
// How many different ways can £2 be made using any number of coins?

#include <iostream>

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

int numCombinations(int sum, int largestCoin)
{
    if (sum < 0) {
        return 0;
    }
    if (sum == 0 || largestCoin == 1) {
        return 1;
    }
    else {
        return numCombinations(sum, largestCoin - 1) + numCombinations(sum - coins[largestCoin - 1], largestCoin);
    }
}

int main()
{
    std::cout << numCombinations(200, 8) << std::endl;
    return 0;
}