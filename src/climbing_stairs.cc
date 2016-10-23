/**
 * You are climbing a stair case.
 * It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 * */
/*Time Limit Exceeded*/

int climb_stairs_recursive(int n)
{
	if (n <= 1)
		return 1;
	else
		return climb_stairs_recursive(n - 1) + climb_stairs_recursive(n -2);
}
int climb_stairs_iterative(int n)
{
	int a = 1, b = 1;
	int i  = 0;
	while (i < n)
	{
		b = a + b;
		a = b - a;
		++i;
	}
	return a;
}
int climbStairs(int n) {
	return climb_stairs_iterative(n);
}
#include <stdio.h>
int main(int argc, char **argv) {
	int n = 10;
	printf("%d\n", climbStairs(n));
}

