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

    bool isBalanced(TreeNode *node, int& treeHeight)
    {
        if (!node)
        {
            treeHeight = 0;
            return true;
        }
        if (!node->left && !node->right)
        {
            treeHeight = 1;
            return true;
        }
        
        int leftHeight = 0;
        bool lb = isBalanced(node->left, leftHeight);
        
        int rightHeight = 0;
        bool rb = isBalanced(node->right, rightHeight);
        
        treeHeight = max(leftHeight, rightHeight) + 1;
        if (lb && rb && abs(leftHeight - rightHeight) <= 1)
        {
            return true;
        }
        return false;
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return true;
        
        int leftHeight = 0;
        bool lb = isBalanced(root->left, leftHeight);
        
        int rightHeight = 0;
        bool rb = isBalanced(root->right, rightHeight);
        
        if (lb && rb && abs(leftHeight - rightHeight) <= 1)
        {
            return true;
        }
        return false;
    }
};
