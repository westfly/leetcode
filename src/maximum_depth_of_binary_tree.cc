
/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along
 * the longest path from the root node down to the farthest
 * leaf node.
 * */
int maxDepth(TreeNode *root) {
	if (root == NULL)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return std::max(leftDepth, rightDepth) + 1;
}
