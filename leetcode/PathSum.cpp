/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return false;
        int val = root->val;
        if (val == sum && !(root->left) && !(root->right))
            return true;
        bool left = hasPathSum(root->left, sum - val);
        bool right = hasPathSum(root->right, sum - val);
        return (left || right);
    }
};
