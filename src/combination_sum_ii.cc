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
		// skip some element candidates sorted
		if (i > curr && candidates[i - 1] == value) {
			continue;
		}
		helper->push_back(value);
		combination_helper(candidates, target-value, i + 1, res, helper);
		helper->pop_back();
	}
}
vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {

	sort(candidates.begin(), candidates.end());
	vector<vector<int> > res;
	vector<int> helper;
	combination_helper(candidates, target, 0, &res, &helper);
	return res;
}
int main(int argc, char* argv[]) {
	vector<int> candidates = {8, 8};
	// vector<int> candidates = {10,1,2,7,6,1,5};
	combinationSum2(candidates, 8);


	return 0;
}
