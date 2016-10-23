#include "code_utils.h"

void combination_helper(vector<int> &candidates, int target,
		                  int curr, vector<vector<int> >* res,
						  vector<int>* helper) {
	if (target < 0) {
		return;
	}
	if (0 == target) {
		res->push_back(*helper);
		print_array(*helper);
		printf("\nsize %d\n", helper->size());
		return;
	}
	for(int i = curr; i < candidates.size(); ++i) {
		int value = candidates[i];
		helper->push_back(value);
		combination_helper(candidates, target-value, i, res, helper);
		helper->pop_back();
	}
}
vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

	sort(candidates.begin(), candidates.end());
	vector<vector<int> > res;
	vector<int> helper;
	combination_helper(candidates, target, 0, &res, &helper);
	return res;
}
int main(int argc, char* argv[]) {
	vector<int> candidates = {2,3,6,7};
	combinationSum(candidates, 7);
	return 0;
}
