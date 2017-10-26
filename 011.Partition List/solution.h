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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *leftHead = new ListNode(-1);
        ListNode *rightHead = new ListNode(-1);
        ListNode *leftCurr = leftHead;
        ListNode *rightCurr = rightHead;
        
        for(ListNode *p = head; p != NULL; p = p->next)
        {
            if(p->val < x)
            {
                leftCurr->next = p;
                leftCurr = leftCurr->next;
            }
            else
            {
                rightCurr->next = p;
                rightCurr = rightCurr->next;
            }
        }
        leftCurr->next = rightHead->next;
        rightCurr->next = NULL;
        return leftHead->next;
    }
};
