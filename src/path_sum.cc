#include "code_utils.h"

bool has_path_sum_helper(TreeNode *root, int sum) {
	if (root) {
		// leaf-node
		if (!root->left && !root->right) {
			return sum == root->val;
		}
		return has_path_sum_helper(root->left, sum - root->val)
				|| has_path_sum_helper(root->right, sum - root->val);
	}
	return false;
}
bool hasPathSum(TreeNode *root, int sum) {
	return has_path_sum_helper(root, sum);
}

int main(int argc, char* argv[]) {

	return 0;
}
