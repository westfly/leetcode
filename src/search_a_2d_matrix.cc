#include "code_utils.h"
/*
 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]
 遗世独立  一身仙风道骨
 肉身凡胎 百般菩萨心肠
 */
/* 二维数组我们可以拉直。
 * 二分法确定target可能在第几行出现。
 * 再用二分法在该行确定target可能出现的位置。时间复杂度O(logn+logm)
 * */
bool search_matrix_log_mn(vector<vector<int> > &matrix, int target)
{
	int left = 0;
	int right = matrix.size();
	while (left < right) {
		int middle = left + (right - left ) / 2;
		int value = matrix[middle][0];
		if (value < target) {
			left = middle + 1;
		} else if (value > target) {
			right = middle;
		} else {
			return true;
		}
	}
	if (right == 0) {
		return false;
	}
	int row = right;
	left = 0;
	right = matrix[row].size();
	while (left < right) {
		int value = matrix[row][middle];
		if (value < target) {
			left = middle + 1;
		} else if (value > target) {
			right = middle;
		} else {
			return true;
		}
	}
	return false;
}
bool search_matrix_mn(vector<vector<int> > &matrix, int target) {
	int i = 0, j = matrix[0].size() - 1;
	while (i < matrix.size() && j >= 0) {
		if (target == matrix[i][j])
			return true;
		else if (target < matrix[i][j])
			j--;
		else
			i++;
	}
	return false;
}
bo
bool searchMatrix(vector<vector<int> > &matrix, int target) {

}
int main(int argc, char* argv[]) {

	return 0;
}
