#include "code_utils.h"

class Solution {
  public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNode(root, NULL, key);
    }
    void FreeNode(TreeNode* root) {
        if (root) {
            delete root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, TreeNode* parent,
                         int key) {
        if (!root) {
            return root;
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, root, key);
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, root, key);
            return root;
        } else {// (root->val == key) {
            if (!root->left || !root->right) {
                
                // 删除节点，比较地址返回非空
                TreeNode* new_root = std::max(root->left,
                                     root->right);
                FreeNode(root);
                return new_root;
            }
            // 存在两个左右子树都不为空
            TreeNode* min = root->right;
            // 如下有两种策略，一种直接交换节点的值再递归
            int random = 2;
            if (random & 1) {
                while (min->left){
                   min = min->left;
                }
                root->val = min->val;
                // 在递归中转换为其它情形删除
                root->right = deleteNode(root->right, min->val);
                return root;
            } else {
                // 交换指针的方法
                TreeNode* min_parent = root;
                while (min->left){
                   min_parent = min;
                   min = min->left;
                }
                if (min_parent != root) {
                    min_parent->left = min->right;
                    min->right = root->right;
                }
                min->left = root->left;
                // delete root;
                FreeNode(root);
                return min;
            } // end-if-random

        } //end-if-key
    }
};

int main(int argc, char *argv[])
{
    
    return 0;
}
