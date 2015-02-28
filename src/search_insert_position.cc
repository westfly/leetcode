#include "code_utils.h"


int searchInsert(int A[], int n, int target) {
	int first = 0;
	int last = n;
	while (first < last) {
		int middle = first + (last - first) /2;
		if (A[middle] == target) {
			return middle;
		} else if (A[middle] < target) {
			first = middle + 1;
		} else {
			last = middle;
		}
	}
	return first;
}
int main(int argc, char* argv[]) {
	int array[10];
	int len = ARRAY_SIZE_UNSAFE(array);
	generate_array(array, len);
	std::sort(array, array+len);
	print_array(array, len);
	int	element = atoi(argv[1]);
	printf("find %d\tat\t%d\n", element,
            searchInsert(array, len, element));
	return 0;
}
