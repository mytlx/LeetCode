# [Swap Nodes in Pairs][1]
> Given a linked list, swap every two adjacent nodes and return its head.  
> 
> **For example**,  
> Given `1->2->3->4`, you should return the list as `2->1->4->3`.  
> 
> Your algorithm should use only constant space. You may **not** modify the values in the list, only nodes itself can be changed.

直接检查`head`和`head->next`，`new`一个`dummy->next = head`，三个指针`prev = dummy,curr = head,succ = head->next`，
交换`curr`和`succ`，并且往后动两步（最好画图做，比较清晰），最后的`succ`要判断是否存在。

    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        ListNode *succ = head->next;

        while(succ)
        {
            prev->next = succ;
            curr->next = succ->next;
            succ->next = curr;

            prev = curr;
            curr = curr->next;
            succ = curr != NULL? curr->next : NULL;
        }
        return dummy->next;
    }

[1]:https://leetcode.com/problems/swap-nodes-in-pairs/description/
