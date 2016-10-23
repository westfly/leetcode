#include "code_utils.h"
int firstElement(int A[], int n, int target) {
	int first = 0;
	int last = n;
	int middle = 0;
	while (first < last) {
		middle = first + ((last - first) >> 1);
		if (A[middle] < target) {
			first = middle + 1;
		} else {
			last = middle;
		}
	}
	return A[first] == target ? first : -1;
}
int lastElement(int A[], int n, int target) {
	int first = 0;
	int last = n;
	int middle = 0;
	while (first < last) {
		middle = first + ((last - first) >> 1);
		if (A[middle] <= target) {
			first = middle + 1;
		} else {
			last = middle;
		}
	}
	return A[--last] == target ? last : -1;
}
vector<int> search_range_rework(int A[], int n, int target) {
	vector<int> result;
	result.push_back(firstElement(A, n, target));
	result.push_back(lastElement(A, n, target));
	return result;
}
vector<int> search_range_stl(int A[], int n, int target)
{
	vector<int> result;
	int* upper = upper_bound(A, A + n, target);
	int* lower = lower_bound(A, A + n, target);
	int left = -1 , right = -1;
	if (*(upper - 1) == target) {
		right = upper - A - 1;
	}
	if (*lower == target) {
		left = lower - A;
	}
	result.push_back(left);
	result.push_back(right);
	return result;
}
int main(int argc, char* argv[]) {

	return 0;
}
