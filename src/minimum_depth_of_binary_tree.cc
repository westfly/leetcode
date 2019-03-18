#include "code_utils.h"
// 需要转换为递归来做，递归的条件是什么？
// 思考一下
int min_depth_internal(TreeNode* root) {
    if (!root) {
        return 0;
    }
    if (root->left && root->right) {
        return std::min(min_depth_internal(root->left),
                min_depth_internal(root->right)) + 1;
    }
    int left = min_depth_internal(root->left);
    int right = min_depth_internal(root->right);
    return std::max(left, right) + 1;
}
int minDepth(TreeNode* root) {
    return min_depth_internal(root);
}
int main(int argc, char *argv[])
{
    
    return 0;
}
