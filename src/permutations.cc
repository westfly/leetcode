/*
 * Given a collection of numbers, return all possible permutations.
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 * */
#include "code_utils.h"

void perm(vector<int> &num, int i,
		   vector<vector<int> >& ret) {
	int count = num.size();
	if (i == count) {
		ret.push_back(num);
	}

	for (int j = i; j < count; j++) {
		swap(num[i], num[j]);
		perm(num, i + 1, ret);
		swap(num[j], num[i]);
	}
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > ret;
	perm(num, 0, ret);
	return ret;
}
#include <iostream>
#include <iterator>
void print_helper(const vector<int> &ctor)
{
	cout<<"[\t";
	copy(ctor.begin(), ctor.end(), ostream_iterator<int>(cout, " "));
	cout<<"]\n";
}
int main(int argc, char **argv) {

	int array [] = {1, 3, 2 };
	vector<int> list(array, array + ARRAY_SIZE_UNSAFE(array));
	vector<vector<int> > result = permute(list);
	for(auto iter = result.begin(); iter != result.end(); ++iter) {
		print_helper(*iter);
	}
	return 0;
}
