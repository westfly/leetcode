#include "code_utils.h"

vector<int> preorderTraversal(TreeNode *root) {
	vector<int> v;
	vector<TreeNode*> stack;
	if (root) {
	        stack.push_back(root);
	}
	while (stack.size() > 0)
	{
		TreeNode* n = stack.back();
		v.push_back(n->val);
		stack.pop_back();
		if (n->right) {
			stack.push_back(n->right);
		}
		if (n->left) {
			stack.push_back(n->left);
		}
	}
	return v;
}
int main(int argc, char* argv[]) {

	return 0;
}
