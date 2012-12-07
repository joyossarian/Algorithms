int maxHeight(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (root)
	{
		int left = maxHeight(root->left);
		int right = maxHeight(root->right);
		return (std::max(left, right) + 1);
	}
	return 0;
}