bool is_balanced_internal(TreeNode* root, int* deep) {
    if (!root) {
        *deep = 0;
        return true;
    }
    int left, right;
    if(is_balanced_internal(root->left, &left)
       && is_balanced_internal(root->right, &right)) {
       *deep = std::max(left, right) + 1;
       return abs(left - right) <= 1;
    }
    return false;

}

bool isBalanced(TreeNode *root) {
    int deep = 0;
    return is_balanced_internal(root, &deep);
}
