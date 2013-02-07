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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head)
            return 0;
        ListNode* cur = head;
        int count = 1;
        ListNode* end = head;
        ListNode* prev = 0;
        while (cur)
        {
            if (count > n)
            {
                prev = end;
                end = end->next;
            }
            else
            {
                ++count;
            }
            cur = cur->next;
        }
        if (prev)
            prev->next = end->next;
        else
        {
            return end->next;
        }
        return head;
    }
};
