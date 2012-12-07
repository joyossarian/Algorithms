
bool isSameTree(TreeNode *p, TreeNode *q) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (!p && !q)
	{
		return true;
	}
	if (!(p && q))
	{
		return false;
	}
	if (p->val != q->val)
	{
		return false;
	}
	bool left = isSameTree(p->left, q->left);
	if (!left)
	{
		return false;
	}
	bool right = isSameTree(p->right, q->right);
	if (!right)
	{
		return false;
	}
	return true;
}