#include "code_utils.h"
// 解析
// 最深的节点一定是左右平衡的，否则还可以继续递归
class Solution {
  public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth;
        return subtreeWithAllDeepest(root, depth);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return root;
        }
        int left_depth, right_depth;
        TreeNode* left_node = subtreeWithAllDeepest(root->left, left_depth);
        TreeNode* right_node= subtreeWithAllDeepest(root->right, right_depth);
        if (left_depth == right_depth) {
            depth = left_depth + 1;
            return root;
        } else if (left_depth < right_depth){
            depth = right_depth + 1;
            return right_node;
        } else {
            depth = left_depth + 1;
            return left_node;
        }
    }
};

int main(int argc, char *argv[])
{
    
    return 0;
}
