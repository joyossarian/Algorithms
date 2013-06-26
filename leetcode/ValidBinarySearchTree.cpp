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

    bool inRange(TreeNode* node, int lower, int upper)
    {
        if (node->val <= lower || node->val >= upper)
            return false;
        bool in = true;
        if (node->left)
        {
            in = inRange(node->left, lower, node->val);
        }
        if (!in)
            return false;
        if (node->right)
        {
            in = inRange(node->right, node->val, upper);
        }
        return in;
    }
    
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return true;
        bool valid = true;
        if (root->left)
            valid = inRange(root->left, INT_MIN, root->val);
        if (!valid)
            return false;
        if (root->right)
            valid = inRange(root->right, root->val, INT_MAX);
        return valid;      
    }
};
