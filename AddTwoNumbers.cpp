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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
        ListNode* lastResult = 0;
        ListNode* head = 0;
        while (l1 || l2)
        {
            int i1 = l1 ? l1->val : 0;
            int i2 = l2 ? l2->val : 0;
            int i3 = i1 + i2 + carry;
            if (i3 > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            i3 %= 10;
            
            ListNode* newNode = new ListNode(i3);
            if (lastResult)
            {
                lastResult->next = newNode;
                lastResult = newNode;
            }
            else
            {
                head = newNode;
                lastResult = newNode;
            }
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        if (carry)
        {
            ListNode* newNode = new ListNode(1);
            lastResult->next = newNode;
        }
        return head;
    }
};