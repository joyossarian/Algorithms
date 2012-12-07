/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* curNode = 0;
        ListNode* result = 0;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                if (curNode == 0)
                {
                    result = l1;
                    curNode = l1;
                }
                else
                {
                    curNode->next = l1;
                    curNode = curNode->next;
                }
                l1 = l1->next;
            }
            else
            {
                if (curNode == 0)
                {
                    result = l2;
                    curNode = l2;
                }
                else
                {
                    curNode->next = l2;
                    curNode = curNode->next;
                }
                l2 = l2->next;
            }
        }
        if (l1)
        {
            if (curNode == 0)
            {
                result = l1;
            }
            else
            {
                curNode->next = l1;
            }
        }
        else if (l2)
        {
            if (curNode == 0)
            {
                result = l2;
            }
            else
            {
                curNode->next = l2;
            }
        }
        return result;
    }
};