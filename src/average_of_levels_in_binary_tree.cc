#include "code_utils.h"
vector<double> averageOfLevels(TreeNode* root) {

}

vector<double> DFSTreeNode(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<double> ans;
}
vector<double> BFSTreeNode(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<double> ans;
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

int main(int argc, const char *argv[])
{
    
    return 0;
}
