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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if (root)
        {
            std::list<TreeNode*> queue;
            queue.push_back(root);
            
            while (!queue.empty())
            {
                std::vector<int> level;
                int queueSize = queue.size();
                int oSize = queueSize;
                for (std::list<TreeNode*>::iterator iter = queue.begin();
                queueSize > 0; --queueSize, ++iter)
                {
                    level.push_back((*iter)->val);
                    if ((*iter)->left)
                    {
                        queue.push_back((*iter)->left);
                    }
                    if ((*iter)->right)
                    {
                        queue.push_back((*iter)->right);
                    }
                }
                result.push_back(level);
                while (oSize > 0)
                {
                    queue.pop_front();
                    --oSize;
                }
                
            }
            
        }
        return result;
    }
};