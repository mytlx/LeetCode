# Remove Linked List Elements
> Remove all elements from a linked list of integers that have value val.  
> Example  
> Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6   
> Return: 1 --> 2 --> 3 --> 4 --> 5  

这道题是删除指定元素值的节点，很容易实现。

	ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* p = head;
        while(p->next != NULL)
        {
            if(p->next->val == val)           
                p->next = p->next->next;          
            else
                p = p->next;
        }
        return head;
    }  
这是一开始的代码，但是运行后发现，这里的head节点是表中第一个节点，而不是哨兵节点，而且，对于`head->val == val`的情况，无法删除第一个节点的元素值。    

	ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode* p = head;
        while(p != NULL && p->next != NULL)
        {
            if(p->next->val == val)           
                p->next = p->next->next;          
            else
                p = p->next;
        }
        if(head != NULL && head->val == val)
            head = head->next;
        return head;
    }  
先删除后面的节点，最后删除头结点，就算是`[1,1,1]，1`这种情况，也可以正常解决。  
