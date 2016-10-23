
/**
 * Implement pow(x, n).
 * */

/*
 * pow_recursive_raw 的方式超時，需要
 *
 **/
#include <stdio.h>
double pow_recursive_raw(double x, int n)
{
	if (n<=1)
		return x;
	else
		return x*pow_recursive_raw(x, n - 1);
}
double pow_recursive_opt(double x, int n)
{
	if (n == 0) {
		return 1;
	}
	printf("%d\n", n); // 为什么n>>1传递的为是负数？
	double pow_divide = pow_recursive_opt(x, n / 2);
	//double pow_divide = pow_recursive_opt(x, n >> 1);
	pow_divide *= pow_divide;
	if (n & 1)
	{
		pow_divide *= x;
	}
	return pow_divide;
}
double pow(double x, int n) {
	if ( n > 0) {
		return pow_recursive_opt(x, n);
	} else {
		return 1/pow_recursive_opt(x, -n);
	}
}


int main(int argc, char **argv) {

	printf("%lf\n", pow(2, 4));
	printf("%lf\n", pow(-1.00000, -2147483648));
	return 0;
}
