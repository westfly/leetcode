#include "code_utils.h"
/*
 * Given an array of integers, every element appears
 * twice except for one. Find that single one.
 * https://oj.leetcode.com/problems/single-number
 * 简单题，利用异或的性质
 * */
int singleNumber(int A[], int n) {
	int r = 0;
	for(int i = 0; i < n; ++i)
	{
		r ^= A[i];
	}
	return r;
}
int main(int argc, char* argv[]) {
	const int len = 5;
	const int arr_len = (len<<1) + 1;
	int array[arr_len];
	generate_array(array, len);
	size_t sum = 0;
	for(int i = 0; i < len; ++i)
	{
		array[len + i] = array[i];
		sum += array[i];
	}
	// 此处利用generate_array 产生的均是正数特性
	array[arr_len - 1] = -sum;
	print_array(array, arr_len);
	printf("sum = %d\t%d\n", -sum, singleNumber(array, arr_len));
	return 0;
}


