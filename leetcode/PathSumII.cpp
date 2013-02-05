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

    void helper(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& result)
    {
        if (!node)
            return;
        bool leaf = (!node->left) && (!node->right);
        path.push_back(node->val);
        if (node->val == sum && leaf)
        {
            result.push_back(path);
        }
        helper(node->left, sum - node->val, path, result);
        helper(node->right, sum - node->val, path, result);
        path.pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        
        if (!root)
        {
            return result;
        }
        vector<int> path;
        helper(root, sum, path, result);
        
        return result;
    }
};
