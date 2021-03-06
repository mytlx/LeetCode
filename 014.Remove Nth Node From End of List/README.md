# [Remove Nth Node From End of List][1]
> Given a linked list, remove the nth node from the end of list and return its head.
> 
> For example,  
> Given linked list: **1->2->3->4->5**, and **n = 2**.  
> After removing the second node from the end, the linked list becomes **1->2->3->5**.
>   
> **Note:**  
> Given n will always be valid.  
> Try to do this in one pass.

还是两个指针的应用，让fast指针先走n步，之后slow和fast同时走，当fast走到末尾，删除slow的后继节点即可。 

    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *slow = dummy;
            ListNode *fast = dummy;

            for(int i = 1; i < n + 1; i++)
                fast = fast->next;
            while(fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            ListNode *temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
            return dummy->next;
        }
    };
    
[1]:https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
