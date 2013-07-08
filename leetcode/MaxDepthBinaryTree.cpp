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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if (!root)
        {
            return 0;
        }
        int leftDepth = maxDepth(root->left) + 1;
        int rightDepth = maxDepth(root->right) + 1;
        if (root->left && root->right)
        {
            return std::max(leftDepth, rightDepth);
        }
        else if (root->left)
        {
            return leftDepth;
        }
        else if (root->right)
        {
            return rightDepth;
        }
        else 
        {
            return 1;
        }
        
    }
};
