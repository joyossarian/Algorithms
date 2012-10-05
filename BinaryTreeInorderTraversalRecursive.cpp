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

    void traHelper(TreeNode* node, std::vector<int>& vec)
    {
        if (!node)
        {
            return;
        }
        traHelper(node->left, vec);
        vec.push_back(node->val);
        traHelper(node->right, vec);
        
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> result;
        if (root)
        {
            traHelper(root, result);
        }
        return result;
    }
};