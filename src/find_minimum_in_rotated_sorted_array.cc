#include "code_utils.h"
/*
 * Suppose a sorted array is rotated at some pivot
 * unknown to you beforehand.
 */
#include <limits.h>
int findMin(vector<int> &num) {
	// 根据题意，应该是查找最小的元素
	int first = 0;
	int last = num.size();
	if (last <= 0) {
		return 0;
	}
	int min = INT_MAX;
	while (first < last) {
		int middle = first + (last - first)/2;
		if (num[first] < num[middle]) {
			min = std::min(min, num[first]);
			first = middle + 1;
		} else { // first >= middle
			min = std::min(min, num[middle]);
			last = middle;
		}
	}
	return min;
}
int main(int argc, char* argv[]) {

	return 0;
}
