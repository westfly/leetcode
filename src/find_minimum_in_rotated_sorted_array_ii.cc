#include "code_utils.h"
/*
 * Suppose a sorted array is rotated at some pivot
 * unknown to you beforehand.
 * refer http://blog.csdn.net/linhuanmars/article/details/40449299
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
	while ((first + 2) < last) {
		int middle = first + (last - first)/2;
		if (num[first] < num[middle]) {
			min = std::min(min, num[first]);
			first = middle + 1;
		} else if (num[first] > num[middle]) {
			min = std::min(min, num[middle]);
			last = middle;
		} else {
			++first;
		}
		printf("zero\t%d\t%d\t%d\n", first, middle, last);
		printf("zero\t%d\t%d\t%d\n", num[first], num[middle], num[last-1]);
	}
	min = std::min(num[last - 1], min);
	min = std::min(num[first], min);
	printf("first\t%d\t%d\n", first, min);
	return min;
}
int main(int argc, char* argv[]) {
	int array [] = {1,1,1,3};
	int len = ARRAY_SIZE_UNSAFE(array);
	vector<int> vt(array, array + len);
	printf("%d\n", findMin(vt));
	return 0;
}
