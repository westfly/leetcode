#include "code_utils.h"
/*
 * reference
 * http://blog.csdn.net/linhuanmars/article/details/20588511
 * */

int search_internal(int A[], int n, int target)
{

	int first = 0;
	int last = n;
	while (first < last) {
		int middle = first + (last - first) / 2;
		int element = A[middle];
		// find it & no duplicate
		if (element == target) {
			return middle;
		}
		// [first     middle           last)
		if (A[first] < element) {
			// 在区间左边查找
			if (A[first] <= target && target < element) {
				last = middle;
			} else {
				first = middle + 1;
			}
		} else if (A[first] > element){
			// 在区间右边查找
			if (element < target && target <= A[last - 1]) {
				first = middle + 1;
			} else {
				last = middle;
			}
		} else { // 最坏的情况下
			++first;
		}
	}
	return -1;
}
bool search(int A[], int n, int target) {
	return search_internal(A, n ,target) >= 0;
}
int main(int argc, char* argv[]) {
	// int array[] = { 4, 5, 1, 2,2, 2, 3 };
	int array [] = {3,1};
	int len = ARRAY_SIZE_UNSAFE(array);
	print_array(array, len);
	int element = 3;
	printf("find %d\t%d\n", element, search_internal(array, len, element));
	return 0;
}
