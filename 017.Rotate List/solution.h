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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || k == 0)
            return head;
        ListNode *p = head;
        int len = 1;
        while(p->next != NULL)
        {
            len++;
            p = p->next;
        }
        p->next = head;
        k = (len - k % len) % len;
        for(int i = 0; i < k; i++)
        {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
