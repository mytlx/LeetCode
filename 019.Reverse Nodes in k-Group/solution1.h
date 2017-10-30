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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL || k == 1)
            return head; 
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head;
        ListNode *head2 = NULL;
        
        bool flag = judge_k(curr, k);
        while(flag)
        {
            head2 = prev;
            prev = prev->next;
            curr = curr->next;
            
            for(int i = 1; i < k; i++)
            {
                prev->next = curr->next;
                curr->next = head2->next;
                head2->next = curr;
                curr = prev->next;
            }
            flag = judge_k(curr, k);
        }
        return dummy->next;
    }
    
    bool judge_k(ListNode *p, int k)
    {
        int i = 0;
        while(p)
        {
            i++;
            if(k == i) return true;
            p = p->next;
        }
        return false;
    }
};
