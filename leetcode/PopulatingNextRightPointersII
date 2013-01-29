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

    void connectHelper(TreeLinkNode* pParent, TreeLinkNode* pNode)
    {
        TreeLinkNode* pLevelNode = pNode;
        while (pParent && pNode)
        {
            if (pParent->left == pNode)
            {
                if (pParent->right)
                {
                    pNode->next = pParent->right;
                    pNode = pNode->next;
                }
                else
                {
                    TreeLinkNode* pNext = pParent->next;
                    while (pNext)
                    {
                        if (pNext->left)
                        {
                            pNode->next = pNext->left;
                            break;
                        }
                        else if (pNext->right)
                        {
                            pNode->next = pNext->right;
                            break;
                        }
                        pNext = pNext->next;
                    }
                    pNode = pNode->next;
                    pParent = pNext;
                }
            }
            else if (pParent->right == pNode)
            {
                TreeLinkNode* pNext = pParent->next;
                    while (pNext)
                    {
                        if (pNext->left)
                        {
                            pNode->next = pNext->left;
                            break;
                        }
                        else if (pNext->right)
                        {
                            pNode->next = pNext->right;
                            break;
                        }
                        pNext = pNext->next;
                    }
                    pNode = pNode->next;
                    pParent = pNext;
            }
        }
        while (pLevelNode)
        {
            if (pLevelNode->left)
            {
                connectHelper(pLevelNode, pLevelNode->left);
                break;
            }
            else if (pLevelNode->right)
            {
                connectHelper(pLevelNode, pLevelNode->right);
                break;
            }
            pLevelNode = pLevelNode->next;
        }
    }

    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)
            return;
        if (root->left)
        {
            connectHelper(root, root->left);
        }
        else if (root->right)
        {
            connectHelper(root, root->right);
        }
    }
};
