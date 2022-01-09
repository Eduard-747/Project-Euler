// If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
// Not all numbers produce palindromes so quickly. For example,
// 349 + 943 = 1292,
// 1292 + 2921 = 4213
// 4213 + 3124 = 7337
// That is, 349 took three iterations to arrive at a palindrome.
// Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. 
// A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
// Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise.
// In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, 
// with all the computing power that exists, has managed so far to map it to a palindrome. 
// In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
// Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
// How many Lychrel numbers are there below ten-thousand?

#include <iostream>
#include <cstring>

bool lyc[10000];

unsigned long long getOpp(const unsigned long long& cur)
{
	unsigned long long opposite = 0;
	for (unsigned long long tempCur = cur; tempCur > 0; tempCur /= 10)
	{	
        opposite = opposite * 10 + tempCur % 10;
    }
	return opposite;
}

bool isLyc(const int& depth, const unsigned long long& cur)
{
	if (depth >= 50) return true;
	if (cur < 10000 && !lyc[cur]) return false;
	unsigned long long opposite = getOpp(cur);
	if (opposite == cur) return false;
	bool result = isLyc(depth+1, cur+opposite);
	if (cur < 10000) {
		lyc[cur] = result;
		lyc[opposite] = result;
	}
	return result;
}

int main()
{
	int count = 0;
	memset(lyc, 1, 10000);
	for (int i = 0; i < 10000; i++) {
		lyc[i] = isLyc(1, i + getOpp(i));
		if (lyc[i]) {
            count++;
        }
	}
	std::cout << count << std::endl ;
    return 0;
}