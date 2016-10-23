/*
 * A robot is located at the top-left corner of a m x n grid
 * (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid
 * (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * */
/*
 * 由于只能往下或者往右走，因此(i, j)只会由(i - 1, j)或者(i, j - 1)到达。
 * 假设，到达(i - 1, j)有f[i - 1, j]种走法，到达(i, j - 1)有f[i, j - 1]
 * 种走法，那么到达(i, j)有f[i, j] = f[i - 1, j] + f[i, j - 1]中走法。
 * */
#include <stdio.h>
#include <string.h>
int unique_paths_dynamic(int m, int n) {
	int f[m][n];
	memset(f, 0, sizeof(int) * m * n);
	for (int i = 0; i < m; i++) {
		f[i][0] = 1;
	}
	for (int j = 0; j < n; j++) {
		f[0][j] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	return f[m - 1][n - 1];
}
/*http://blog.csdn.net/linhuanmars/article/details/22126357*/
#include <algorithm>
int unique_paths_math(int m, int n)
{
	//C(n+m-2, n - 1)
	int min = std::min(m, n);
	double An = 1;
	double Bn = 1;
	for(int i = 1; i < min; ++i) {
		An *= i;
		Bn *= (m + n - 1 - i);
	}
	return Bn/An;
}

int uniquePaths(int m, int n)
{

	return unique_paths_dynamic(m, n);
}
int main(int argc, char **argv) {

	for(int i = 1; i < 4; ++i)
		for (int j = 1; j < 4; ++j )
			printf("%d\t%d\t%d\n", i, j, uniquePaths(i, j));
	return 0;
}

