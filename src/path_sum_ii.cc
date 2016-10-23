#include "code_utils.h"


void path_sum_helper(TreeNode *root, int sum,
					 vector<int>* curr,
					  vector<vector<int> >* result) {
	if (root) {
		// leaf-node
		curr->push_back(root->val);
		if (!root->left && !root->right) {
			if (sum == root->val)
			{
				result->push_back(*curr);
			}
		}
		path_sum_helper(root->left, sum - root->val, curr, result);
		path_sum_helper(root->right, sum - root->val,curr, result);
		curr->pop_back();
	}
}
vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > result;
	vector<int> curr;
	path_sum_helper(root, sum, &curr, &result);
	return result;
}

int main(int argc, char* argv[]) {

	return 0;
}
