/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == null || head->next == null) 
          return head;
        ListNode *p = head->next;
        if (head->val == p->val) 
        {
          while (p != NULL && head->val == p->val) 
            p = p.next;	
          return deleteDuplicates(p);
        }
        else 
        {
          head->next = deleteDuplicates(head->next);
          return head;
        }
    }
};
