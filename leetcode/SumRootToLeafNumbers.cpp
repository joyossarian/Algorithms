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

    void sumHelper(TreeNode* node, int& finalResult, int pathSum)
    {
        // reach to leaf
        if (!node)
            return;
        int addedVal = pathSum * 10 + node->val;
        
        if (!node->left && !node->right)
        {
            finalResult += addedVal;
        }
        if (node->left)
        {
            sumHelper(node->left, finalResult, addedVal);
        }
        if (node->right)
        {
            sumHelper(node->right, finalResult, addedVal);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        if (root)
        {
            sumHelper(root, result, 0);
        }
        return result;
    }
};
