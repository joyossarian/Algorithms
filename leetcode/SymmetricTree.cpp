/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
bool symHelper(TreeNode* left, TreeNode* right)
{
    if (!left && right)
        return false;
    if (left && !right)
        return false;
    if (!left && !right)
        return true;
    if (left->val != right->val)
    {
        return false;
    }
    else
    {
        bool result = symHelper(left->left, right->right) &
            symHelper(left->right, right->left);
        return result;
    }
    return false;
}

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return true;
        
        return symHelper(root->left, root->right);
    }
};
