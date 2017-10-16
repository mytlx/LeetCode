  /**
 	* Definition for singly-linked list.
 	* struct ListNode {
 	*     int val;
 	*     struct ListNode *next;
 	* };
	 */
	struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
	{
	    struct ListNode head ;
	    struct ListNode *pnew = &head;
	    pnew->next = l1;		    
	    while(l1 != NULL && l2 != NULL)
	    {
	        if(l1->val > l2->val)
	        {
	            struct ListNode* temp = NULL;
	            temp = l2->next;
	            l2->next = pnew->next;
	            pnew->next = l2;
	            l2 = temp;
	        }
	        else
	            l1 = l1->next;
	        pnew = pnew->next;
	    }	    
	    if(l2 != NULL)
	        pnew->next = l2;	    
	    return head.next; 
	}
