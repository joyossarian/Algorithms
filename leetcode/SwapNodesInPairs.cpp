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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head)
            return 0;
        
        ListNode* prev = 0;
        ListNode* cur = head;
        ListNode* next = cur->next;
               
        while (cur && next)
        {
            if (prev)
            {
                prev->next = next;
            }
            if (!prev)
            {
                head = next;
            }
            cur->next = next->next;
            next->next = cur;
            prev = cur;
            cur = cur->next;
            if (cur && cur->next)
            {
                next = cur->next;
            }
            else
            {
                next = 0;
            }
        }
        return head;
    }
};
