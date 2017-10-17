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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* p = head;
        while(p != NULL && p->next != NULL)
        {
            if(p->next->val == val)           
                p->next = p->next->next;          
            else
                p = p->next;
        }
        if(head != NULL && head->val == val)
            head = head->next;
        return head;
    }
};
