/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void connectHelper(TreeLinkNode* pNode)
    {
        if (pNode && pNode->left && pNode->right)
        {
            pNode->left->next = pNode->right;
            if (pNode->next)
            {
                pNode->right->next = pNode->next->left;
            }
            connectHelper(pNode->left);    
            connectHelper(pNode->right);
        }
    }
    
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return;
        root->next = 0;
        if (root->left && root->right)
        {
            root->left->next = root->right;
            connectHelper(root->left);
            connectHelper(root->right);
        }
    }
};
