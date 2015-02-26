#include "code_utils.h"
/*
 *  Given an array of integers, every element appears
 *  three times except for one. Find that single one.
 *  Note:
 *  Your algorithm should have a linear runtime complexity.
 *  Could you implement it without using extra memory?
 *  https://oj.leetcode.com/problems/single-number-ii
 *  异或是两位的加法，如何模拟三位的加法？
 * */
int single_number_ex(int A[], int n) {
	int low = 0;
	int high = 0;
	for (int i = 0; i < n; ++i)
	{
		low  ^= A[i] & ~high;
		high ^= A[i] & ~low;
	}
	printf("low %d\t high %d\n", low, high);
	return low;
}
/*  reference
 *  http://blog.csdn.net/jiadebin890724/article/details/23306837
 *  int 数据共有32位，可以用32变量存储 这 N 个元素中各个二进制位上  1  出现的次数，
 *  最后 在进行 模三 操作，如果为1，那说明这一位是要找元素二进制表示中为 1 的那一位
 */
int single_number_common(int A[], int n) {
	int bitnum[32] = { 0 };
	int res = 0;
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < n; j++) {
			bitnum[i] += (A[j] >> i) & 1;
		}
		res |= (bitnum[i] % 3) << i;
	}
	return res;
}
int singleNumber(int A[], int n) {
	int r = rand();
	if (r % 2)
	{
		single_number_common(A, n);
	}
	else
	{
		single_number_ex(A, n);
	}
}
int main(int argc, char* argv[]) {
	const int len = 5;
	const int arr_len = (len*3) + 1;
	int array[arr_len];
	generate_array(array, len);
	size_t sum = 0;
	for(int i = 0; i < len; ++i)
	{
		array[len + i] = array[i];
		array[len + len + i] = array[i];
		sum += array[i];
	}
	// 此处利用generate_array 产生的均是正数特性
	array[arr_len - 1] = -sum;
	print_array(array, arr_len);
	printf("sum = %d\t%d\n", -sum, singleNumber(array, arr_len));
	return 0;
}


