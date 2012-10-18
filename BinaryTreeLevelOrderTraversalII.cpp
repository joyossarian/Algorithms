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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<TreeNode*> searchSpace;
        vector<vector<int> > result;
        if (!root)
        {
            return result;
        }
        searchSpace.push_back(root);
        while (!searchSpace.empty())
        {
            size_t resSize = result.size();
            result.resize(resSize + 1);
            size_t levelSize = searchSpace.size();
            for (size_t i = 0; i < levelSize; ++i)
            {
                TreeNode* node = searchSpace[i];
                result[resSize].push_back(node->val);
                if (node->left)
                {
                    searchSpace.push_back(node->left);
                }
                if (node->right)
                {
                    searchSpace.push_back(node->right);
                }
            }
            searchSpace.erase(searchSpace.begin(), searchSpace.begin() + levelSize);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};