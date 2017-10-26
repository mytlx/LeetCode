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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode *odd_dummy = new ListNode(-1);
        ListNode *even_dummy = new ListNode(-1);
        ListNode *odd_cur = odd_dummy;
        ListNode *even_cur = even_dummy;
        int i = 1;
        for(ListNode *p = head; p != NULL; p = p->next, i++)
        {
            if(i % 2 != 0)
            {
                odd_cur->next = p;
                odd_cur = odd_cur->next;
            }
            else
            {
                even_cur->next = p;
                even_cur = even_cur->next;
            }
        }
        odd_cur->next = even_dummy->next;
        even_cur->next = NULL;
        return odd_dummy->next;
    }
};
