struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* TrimTreeNode(TreeNode* root, int lvalue, int rvalue) {
    if (!root) {
        return root;
    } 
    if (root->val < lvalue) {
        return TrimTreeNode(root->right, lvalue, rvalue);
    }
    if (root->val > rvalue) {
        return TrimTreeNode(root->left, lvalue, rvalue);
    }
    root->left = TrimTreeNode(root->left, lvalue, rvalue);
    root->right = TrimTreeNode(root->right, lvalue, rvalue);
    return root;
}
