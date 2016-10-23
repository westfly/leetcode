/**
 * Given a non-negative number represented as an array of digits,
 * plus one to the number.
 * The digits are stored such that the most significant digit is
 * at the head of the list.
 * */

#include "code_utils.h"
vector<int> plusOne(vector<int> &digits) {
	vector<int> result;
	result.reserve(digits.size() + 1);
	int carrier = 1;
	int sum = 0;
	for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
		sum = *iter + carrier;
		carrier = sum / 10;
		result.push_back(sum % 10);
	}
	if (carrier) {
		result.push_back(carrier);
	}
	reverse(result.begin(), result.end());
	return result;
}
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;
void print_helper(const vector<int> &array)
{
	copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
}
int main(int argc, char **argv) {
	int array[] = {9, 9, 9, 9, 9};
	int len = ARRAY_SIZE_UNSAFE(array);
	vector<int> a(array, array + len);
	vector<int> b = plusOne(a);
	print_helper(a);
	print_helper(b);
	return 0;
}
