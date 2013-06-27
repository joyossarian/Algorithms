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
        
        ListNode* cur = head;
        if (!cur)
            return head;
        ListNode* next = cur->next;
        ListNode* prev = 0;
        ListNode* nnext = 0;
            
        while (cur && next)
        {
            nnext = next->next;
            if (prev)
            {
                prev->next = next;
            }
            else
            {
                head = next;
            }
            next->next = cur;
            cur->next = nnext;
        
            prev = cur;
            cur = nnext;
            if (cur)
                next = cur->next;
        }
        
        return head;
    }
};
