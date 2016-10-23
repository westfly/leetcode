/*
 *
 * */
bool is_symmetric(TreeNode *left, TreeNode *right)
{
    if (left && right)
    {
        if(left->val != right->val) {
            return false;
        }
        return is_symmetric(left->left, right->right)
              && is_symmetric(left->right, right->left);
    }
    return !left && !right;
}

bool isSymmetric(TreeNode *root)
{
    if (!root) {
        return true;
    }
    return is_symmetric(root->left, root->right);
}
