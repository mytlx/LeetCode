# [Reverse Nodes in k-Group][1]
> Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.  
> **k** is a **positive** integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.  
> 
> You may not alter the values in the nodes, only nodes itself may be changed.   
> 
> Only constant memory is allowed.  
> 
> For example,  
> Given this linked list: `1->2->3->4->5`  
> 
> For `k = 2`, you should return: `2->1->4->3->5`  
> 
> For `k = 3`, you should return: `3->2->1->4->5`

**方法一：**  
定义一个函数用来判断剩余链表节点是否大于k，返回bool，用于主函数中的循环条件

	bool judge_k(ListNode *p, int k)
    {
        int i = 0;
        while(p)
        {
            i++;
            if(k == i) return true;
            p = p->next;
        }
        return false;
    }


主函数中reverse可以参考[Reverse Linked List II][2]，调整`head2,prev,curr`的位置，reverse链表，外层加上while循环，判断条件用上面函数   

	bool flag = judge_k(curr, k);
	while(flag)
	{
	    head2 = prev;
	    prev = prev->next;
	    curr = curr->next;
	    
	    for(int i = 1; i < k; i++)
	    {
	        prev->next = curr->next;
	        curr->next = head2->next;
	        head2->next = curr;
	        curr = prev->next;
	    }
	    flag = judge_k(curr, k);
	}
![](https://i.imgur.com/b6zQqtO.png)

**方法二（递归）：**  

    class Solution {
    public:
      ListNode* reverseKGroup(ListNode* head, int k)
      {
        if (head == NULL || head->next == NULL || k < 2)
          return head;
        ListNode *next_group = head;
        for (int i = 0; i < k; ++i)
        {
          if (next_group != NULL)
            next_group = next_group->next;
          else
            return head;
        }
        // new_group is the head of next group
        // new_next_group is the new head of next group after reversion
        ListNode *new_next_group = reverseKGroup(next_group, k);
        ListNode *prev = NULL, *cur = head;
        while (cur != next_group)
        {
          ListNode *next = cur->next;
          cur_next = prev != NULL ? prev : new_next_group;
          prev = cur;
          cur = next;
        }
        return prev;
      }
    }


[1]:https://leetcode.com/problems/reverse-nodes-in-k-group/description/
[2]:https://github.com/mytlx/LeetCode/tree/master/016.Reverse%20Linked%20List%20II
