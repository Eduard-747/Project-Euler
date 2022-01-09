// If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

#include <iostream>

int firstTwenty[] = {3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8,6};
int tens[] = {3,6,6,5,5,5,7,6,6};
int hundred = 7;

int main()
{
	int sum = 0;
	for (int i = 1; i <= 999; i++) 
    {
		if (i >= 100) {
			sum += firstTwenty[i / 100 - 1];
			sum += hundred;
			if (i % 100) {
				sum += 3;
			} else {
				continue;
            }
		}
		if (i % 100 < 20)
			sum += firstTwenty[i % 100 - 1];
		else {
			sum += tens[i / 10 % 10 - 1];
			if (i % 10)
				sum += firstTwenty[i % 10 - 1];
		}
	}
	sum += firstTwenty[0] + 8;
	std::cout << sum << std::endl ;
	return 0;
}