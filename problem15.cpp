// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
// How many such routes are there through a N×N grid?

#include <iostream>

int main()
{
    std::cout << "Enter N: " ;
    int N;
    std::cin >> N ;
	long long grid[N][N] {0};
	grid[0][0] = 1;
	for (int i = 1; i < N; i++) 
    {
		for (int j = 0; j <= i; j++) 
        {
			grid[j][i] = (j > 0 ? grid[j - 1][i] : 0) + grid[j][i - 1];
			grid[i][j] = grid[j][i];
		}
	}
	std::cout << grid[N - 1][N - 1] << std::endl;
	return 0;
}