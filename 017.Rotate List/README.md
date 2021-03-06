# [Rotate List][1]
> Given a list, rotate the list to the right by k places, where k is non-negative.  
> 
> **For example:**  
> Given `1->2->3->4->5->NULL` and `k = 2`,  
> return `4->5->1->2->3->NULL`.

先遍历一遍，得出链表长度`len`，注意`k`可能大于`len`，因此令`k %= len`。将尾节点`next`指针指向`head`，形成一个环，接着往后跑`(len-k) % len`步，因为`k`可能是`len`的整数倍，所以用`(len-k) % len`，从这里断开，就是要求的结果了

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

[1]:https://leetcode.com/problems/rotate-list/description/
