#include "code_utils.h"
// Find the sum of all left leaves in a given binary tree.
// 注意题目要的是左子树的叶子节点，需用从父节点开始看起
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
       int ans = 0;
       sumOfLeftLeaves(root, ans);
       return ans;
    }
    void sumOfLeftLeaves(TreeNode* root, int& ans) {
        if (!root) {
            return;
        }
        sumOfLeftLeaves(root->left, ans);
        if (root->left && !root->left->left &&
            !root->left->right) {
            ans += root->left->val;
        }
        sumOfLeftLeaves(root->right, ans);
    }
};
int main(int argc, char *argv[])
{
    (void)argc; 
    (void)argv; 
    return 0;
}
