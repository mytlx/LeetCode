# Add Two Numbers
> You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
>
> You may assume the two numbers do not contain any leading zero, except the number 0 itself.
>
> **Input**: (2 -> 4 -> 3) + (5 -> 6 -> 4)  
> **Output**: 7 -> 0 -> 8

这个题目的意思是每个链表倒序存储一个多位整数，每个节点只存一位，最后用一个链表保存两个整数相加的结果。    

new构造函数申请内存保存相加结果，carry保存进位信息 

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
处理l1剩余的高位  

	while(l1)
	{
	    pNext = new ListNode((l1->val + carry)%10);
	    carry = (l1->val + carry) / 10;
	    pNode->next = pNext;
	    pNode = pNext;
	    l1 = l1->next;
	}
处理l2剩余的高位  

	while(l2)
	{
	    pNext = new ListNode((l2->val + carry)%10);
	    carry = (l2->val + carry) / 10;
	    pNode->next = pNext;
	    pNode = pNext;
	    l2 = l2->next;
	}
处理进位 

	if(carry)
    {
        pNext = new ListNode(carry);
        pNode->next = pNext;
    }  
