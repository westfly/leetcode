/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 * */


int square_recursive(int x)
{
	unsigned long long first = 0;
	unsigned long long last = (x + 1) >> 1;
	unsigned long long mid = 0;
	unsigned long long pow = 0;
	while (first < last) {
		mid = first + ((last - first) >> 1);
		pow = mid * mid;
		if (pow == x)
			return mid;
		else if (pow < x)
			first = mid + 1;
		else
			last = mid - 1;
	}
	pow = last * last;
	if (pow > x)
		--last;
	return last;

}
int sqrt(int x) {
	return square_recursive(x);
}

#include <stdio.h>
int main(int argc, char **argv) {
	int n = 167;
	printf("%d\t%d\n", n, sqrt(n));
}
