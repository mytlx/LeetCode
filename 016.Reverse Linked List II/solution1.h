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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head, *succ = NULL;
        ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;
        if(head == NULL || head->next == NULL) return head;
        for(int i = 1;i < m; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        l1 = prev;
        prev->next = NULL;
        l2 = curr;
        for(int i = m; i < n; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        l3 = curr->next;
        curr->next = NULL;
        l2 = reverse(l2);
        l1->next = l2;
        while(l2->next != NULL)
            l2 = l2->next;
        l2->next = l3;
        return dummy->next;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode *prev = NULL, *curr = head, *succ = NULL;
        while(curr != NULL)
        {
            succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
        }
        return prev;
    }
};
