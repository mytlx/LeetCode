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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *curr = head;
        ListNode *prev = dummy;
        
        while(curr != NULL)
        {
            bool flag = false;
            while(curr->next != NULL && curr->val == curr->next->val)
            {
                flag = true;
                curr->next = curr->next->next;
            }
            if(flag)
            {
                prev->next = curr->next;
                curr = curr->next;
                continue;
            }
            prev = curr;
            curr = curr->next;       
        }
        return dummy->next;
    }
};
