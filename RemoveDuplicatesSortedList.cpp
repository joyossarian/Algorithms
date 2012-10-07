class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* curNode = head;
        ListNode* prevNode = 0;
        while (curNode)
        {
            if (prevNode && prevNode->val == curNode->val)
            {
                prevNode->next = curNode->next;
                delete curNode;
                curNode = prevNode->next;
            }
            else
            {
                prevNode = curNode;
                curNode = curNode->next;
            }
        }
        return head;
    }
};