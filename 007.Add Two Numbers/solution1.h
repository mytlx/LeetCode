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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = NULL;
        ListNode* pNode = NULL;
        ListNode* pNext = NULL;
        int carry = 0;
        while(l1 && l2)
        {
            pNext = new ListNode((l1->val + l2->val + carry) % 10 );
            carry = (l1->val + l2->val + carry) / 10;
            if(head == NULL)
                head = pNode = pNext;
            else
            {
                pNode->next = pNext;
                pNode = pNext;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            pNext = new ListNode((l1->val + carry)%10);
            carry = (l1->val + carry) / 10;
            pNode->next = pNext;
            pNode = pNext;
            l1 = l1->next;
        }
        while(l2)
        {
            pNext = new ListNode((l2->val + carry)%10);
            carry = (l2->val + carry) / 10;
            pNode->next = pNext;
            pNode = pNext;
            l2 = l2->next;
        }
        if(carry)
        {
            pNext = new ListNode(carry);
            pNode->next = pNext;
        }
        return head;        
    }
};
