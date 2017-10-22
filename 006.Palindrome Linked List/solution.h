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
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* last = slow->next;
        ListNode* prev = head;
        while(last->next)
        {
            ListNode* temp = last->next;
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }
        while(slow->next)
        {
            slow = slow->next;
            if(prev->val != slow->val)
                return false;
            prev = prev->next;
        }
        return true;           
    }
};
