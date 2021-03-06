# [Reverse Linked List II][1]
> Reverse a linked list from position m to n. Do it in-place and in one-pass.  
> **For example:**  
> Given `1->2->3->4->5->NULL`, m = 2 and n = 4,  
> return `1->4->3->2->5->NULL`.  
> 
> **Note:**  
> Given m, n satisfy the following condition:  
> 1 ≤ m ≤ n ≤ length of list.

**方法一：**  
这道题和[**Reorder List**][2]思路相同，先**cut**，再**reverse**，最后**merge**。

1. **cut**  
这题需要将list分成三部分，声明三个指针l1,l2,l3，l1指向第n-1个节点，l2指向第n个节点，l3指向第m+1个节点  
	<pre>
	ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy, *curr = head, *succ = NULL;
    ListNode *l1 = NULL, *l2 = NULL, *l3 = NULL;
    if(head == NULL || head->next == NULL) return head;
    for(int i = 1;i < m; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    l1 = prev;
    prev->next = NULL;
    l2 = curr;
    for(int i = m; i < n; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    l3 = curr->next;
    curr->next = NULL;</pre>

2. **reverse**
	<pre>
	ListNode* reverse(ListNode* head)
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
    }</pre>

3. **merge**
	<pre>
	l1->next = l2;
    while(l2->next != NULL)
        l2 = l2->next;
    l2->next = l3;</pre>


**方法二（迭代）：**  
这个方法要比第一个方法简单许多，找到第m个节点，声明head2指向它，以head2为头结点，将后续节点依次插入head2后（头插法）
![](https://i.imgur.com/kRaEHd5.png)

	
	class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int m, int n)
		{
			ListNode *dummy = new ListNode(-1);
			dummy->next = head;
	
			ListNode *prev = dummy;
			for (int i = 0; i < m - 1; i++)
				prev = prev->next;
			ListNode *head2 = prev;
	
			prev = head2->next;
			ListNode *cur = prev->next;
			for (int i = m; i < n; i++)
			{
				prev->next = cur->next;
				cur->next = head2->next;
				head2->next = cur;
				cur = prev->next;
			}
			return dummy->next;
		}
	};




[1]:https://leetcode.com/problems/reverse-linked-list-ii/description/
[2]:https://github.com/mytlx/LeetCode/tree/master/015.Reorder%20List
