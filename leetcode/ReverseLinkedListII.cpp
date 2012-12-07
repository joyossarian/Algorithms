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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* curNode = head;
        ListNode* preNode = 0;
        int curPos = 1;
        bool revState = false;
        
        ListNode* revHead = 0;
        ListNode* revTail = 0;
        ListNode* prevRev = 0;
        ListNode* afterRev = 0;
        
        while (curNode)
        {
            if (curPos == m)
            {
                revHead = curNode;
                prevRev = preNode;
            }
            if (curPos == m + 1)
            {
                revState = true;
            }
            if (curPos == n)
            {
                revTail = curNode;
                afterRev = curNode->next;
                curNode->next = preNode;
                break;
            }
            if (revState)
            {
                ListNode* nextNode = curNode->next;
                curNode->next = preNode;   
                preNode = curNode;
                curNode = nextNode;
                ++curPos;
            }
            else
            {
                preNode = curNode;
                curNode = curNode->next;
                ++curPos;
            }
        }
        if (revHead)
        {
            revHead->next = afterRev;
        }
        if (prevRev)
        {
            prevRev->next = revTail;
        }
        
        if (m == 1)
        {
            return revTail;
        }
        
        return head;
    }
};