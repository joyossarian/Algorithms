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

    bool isSymmetricHelper(TreeNode* left, TreeNode* right)
    {
        if (!left && right)
        {
            return false;
        }
        else if (left && !right)
        {
            return false;
        }
        else if (!left && !right)
        {
            return true;
        }
        if (left->val != right->val)
        {
            return false;
        }
        bool leftSym = isSymmetricHelper(left->left, right->right);
        bool rightSym = isSymmetricHelper(left->right, right->left);
        return (leftSym && rightSym);
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
        {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }
};