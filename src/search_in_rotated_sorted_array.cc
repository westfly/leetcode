#include "code_utils.h"
/*
 * Suppose a sorted array is rotated at some pivot unknown
 * to you beforehand.
 * You are given a target value to search.
 * If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * */
int search(int A[], int n, int target) {
	int first = 0;
	int last = n;
	while (first < last)
	{
		int middle = first + (last - first) /2;
		int element = A[middle];
		// find it & no duplicate
		if (element == target) {
			return middle;
		}
		// [first     middle           last)
		if (A[first] <= element ) {
			// 在区间左边查找
			if (A[first] <= target && target < element) {
				last = middle;
			} else {
				first = middle + 1;
			}
		} else {
			// 在区间右边查找
			if (element < target && target <= A[last - 1]) {
				first = middle + 1;
			} else {
				last = middle;
			}
		}
	}
	return -1;
}
int main(int argc, char* argv[]) {
	int array[] = {
		4,5, 1, 2,3
	};
	int len = ARRAY_SIZE_UNSAFE(array);
	print_array(array, len);
	int element = 2;
	printf("find %d\t%d\n", element, search(array, len, element));
	return 0;
}
