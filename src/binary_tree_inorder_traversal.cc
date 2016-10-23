#include "code_utils.h"
vector<int> inorderTraversal(TreeNode *root)
{
    vector<TreeNode*> stack;
    vector<int> v;

    while(stack.size()>0 || root!=NULL) {
    	if (root) {
    		stack.push_back(root);
    		root = root->left;
    	} else {
    		root = stack.back();
    		stack.pop_back();
    		v.push_back(root->val);
    		root = root->right;
    	}
    }
    return v;
}
int main(int argc, char* argv[]) {

	return 0;
}
