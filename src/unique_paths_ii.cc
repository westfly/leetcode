#include "code_utils.h"

// refer http://blog.csdn.net/pickless/article/details/9949557
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {

	if (obstacleGrid.empty() || obstacleGrid[0].empty()
			|| obstacleGrid[0][0] == 1) {
		return 0;
	}
	const int m = obstacleGrid.size();

	const int n = obstacleGrid[0].size();
	int f[m][n];
	memset(f, 0, sizeof(int) * m * n);
	f[0][0] = 1;
	for (int i = 1; i < m; ++i) {
		f[i][0] = obstacleGrid[i][0] == 1 ? 0 : f[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		f[0][i] = obstacleGrid[0][i] == 1 ? 0 : f[0][i - 1];
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (obstacleGrid[i][j] == 1) {
				f[i][j] = 0;
			} else {
				f[i][j] += obstacleGrid[i - 1][j] == 1 ? 0 : f[i - 1][j];
				f[i][j] += obstacleGrid[i][j - 1] == 1 ? 0 : f[i][j - 1];
			}
		}
	}

	return f[m - 1][n - 1];
}
int main(int argc, char **argv) {
	//uniquePathsWithObstacles()
	return 0;
}
