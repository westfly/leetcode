/*Given a binary search tree with non-negative values,
 *find the minimum absolute difference between values
 of any two nodes.
 */
#include "code_utils.h"
#include <limits.h>
// 如果是一个二叉树话，可以遍历一遍树，然后排序
// 从最后的排序数组中找到间隔最小的
//
// 题中说的是bst，其中序遍历得到的序列是有序的。
// 可以避免排序的过程，但空间复杂度为 0(n)
// 
// 但我们如果能够记录其前一个节点，则能把空间
// 降低到 O(1)
class Solution {
 public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        InOrderTravel(root, NULL, ans);
        return ans;
    }
    void InOrderTravel(TreeNode* root, TreeNode* prev, int& ans) {
        if (!root) {
            return;
        }
        InOrderTravel(root->left, prev, ans);
        if (prev) {
            ans = std::min(ans, root->val - prev->val);
        }
        prev = root;
        InOrderTravel(root->right, prev, ans);
    }
};
int main(int argc, char *argv[])
{
    return 0;
}
