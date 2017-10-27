# [Reorder List][1]
> Given a singly linked list L: L0→L1→…→Ln-1→Ln,  
> reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…  
> 
> You must do this in-place without altering the nodes' values.  
> 
> For example,  
> Given `{1,2,3,4}`, reorder it to `{1,4,2,3}`.

先利用快慢指针将链表从中间**cut**，将后半部分链表**reverse**一下，最后将**merge** the two lists
  
1. **cut**
	<pre>
	ListNode *fast = head, *slow = head, *prev = NULL;
	while(fast != NULL && fast->next != NULL)
	{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
	}
	prev->next = NULL;  //截断链表
	</pre>


2. **reverse**
	<pre> 
	ListNode *reverse(ListNode* head)
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
	</pre>

3. **merge**
	<pre>
	ListNode *curr = head;
	ListNode *tmp = NULL;
	while(curr->next != NULL)
	{
			tmp = curr->next;
			curr->next = slow;
			slow = slow->next;
			curr->next->next = tmp;
			curr = tmp;
	}
	curr->next = slow;
	</pre>


[1]:https://leetcode.com/problems/reorder-list/description/
