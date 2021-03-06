# Remove Duplicates from Sorted List

> Given a sorted linked list, delete all duplicates such that each element appear only once.  
> For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.  

这是一道很简单的题，循环判断两节点是否相等，相等删除节点即可，不过有很多需要注意的细节。  

	struct ListNode* deleteDuplicates(struct ListNode* head) 
	{
	    struct ListNode* curr = head->next;
	    struct ListNode* prev = head;	    
	    while(prev != NULL)
	    {
	        if(prev == head)
	            curr = prev->next;	    	        
	        if(prev->val == curr->val)
	        {
	            prev->next = curr->next;
	            curr = curr->next;
	        }
	        else
	        {
	            prev = curr;
	            curr = curr->next;
	        }	      
	    }
	    return head;
	}
这是我最开始的代码，由于没考虑**空链表**的情况，所以报出了 `member access within null pointer of type 'struct ListNode'`的错误提示。（`head`如果为`null`, 则`head->next`不存在）   
改进后的代码如下：

	struct ListNode* deleteDuplicates(struct ListNode* head) 
	{
	    struct ListNode* curr = NUll;
	    struct ListNode* prev = head;	    
	    while(prev != NULL)
	    {
	        if(prev == head)
	            curr = prev->next;	    	        
	        if(prev->val == curr->val)
	        {
	            prev->next = curr->next;
	            curr = curr->next;
	        }
	        else
	        {
	            prev = curr;
	            curr = curr->next;
	        }	      
	    }
	    return head;
	}
本以为这样一定可以了，但是运行发现，同样的错误提示，如果链表只有一个节点`curr`指向`NULL`而`curr->next`不存在，所以报错，于是再加入`curr`是否为空的判断语句。  

	struct ListNode* deleteDuplicates(struct ListNode* head) 
	{
	    struct ListNode* curr = NULL;
	    struct ListNode* prev = head;
	    
	    while(prev != NULL)
	    {
	        if(prev == head)
	            curr = prev->next;
	        if(curr != NULL)
	        {
	            if(prev->val == curr->val)
	            {
	                    prev->next = curr->next;
	                curr = curr->next;
	            }
	            else
	            {
	                prev = curr;
	                curr = curr->next;
	            }
	        }
	        else
	            break;
	    }
	    return head;
	}
至此，大功告成。
