#include "code_utils.h"
// BFS和DFS两种方式遍历所有的节点
// 对于层序遍历（BFS）需要记录层，通过双缓冲的方式解决
// 对于深度遍历（DFS）记录的层，通过数组来解决
class Solution {
 public:
    vector<double> averageOfLevels(TreeNode* root) {
        return DFSTreeNode(root);
    }

    vector<double> DFSTreeNode(TreeNode* root) {
        if (!root) {
            return {};
        }
        // 注意表示的精度
        vector<long>  depth_sum;
        vector<int>  depth_size;
        DFSTreeNode(root, 0, depth_sum, depth_size);
        vector<double> ans(depth_sum.size());
        for (auto i = 0; i < depth_sum.size(); ++i) {
            ans[i] = depth_sum[i] / depth_size[i];
        }
        return ans;
    }

    void DFSTreeNode(TreeNode* root, int depth,
                               vector<long>& depth_sum,
                               vector<int>& depth_size) {
        if (!root) {
            return;
        }
        if (depth > depth_sum.size()) {
            depth_sum.push_back(root->val);
            depth_size.push_back(1);
        } else {
            depth_sum[depth] += root->val;
            ++depth_size[depth];
        }
        if (root->left) {
            DFSTreeNode(root->left, depth + 1, depth_sum, depth_size);
        }
        if (root->right) {
            DFSTreeNode(root->right, depth + 1, depth_sum, depth_size);
        }
    }
    vector<double> BFSTreeNode(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<double> ans;
        // 双缓冲切换的方式解决
        vector<TreeNode*> curr;
        vector<TreeNode*> next;
        curr.push_back(root);
        while (!curr.empty()) {
            double sum = 0;
            for (auto& node : curr) {
                if (node->right) {
                    next.push_back(node->right);
                }
                if (node->left) {
                    next.push_back(node->left);
                }
                sum += node->val;
            }
            ans.push_back(sum / curr.size());
            curr.swap(next);
            next.clear();
        }
        return ans;
    }
};
int main(int argc, const char *argv[])
{
    
    return 0;
}
