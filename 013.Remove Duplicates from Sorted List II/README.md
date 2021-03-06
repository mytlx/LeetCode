# [Remove Duplicates from Sorted List II][1]
> Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
> 
> For example,  
> Given `1->2->3->3->4->4->5`, return `1->2->5`.   
> Given `1->1->1->2->3`, return `2->3`.

这个的[版本一][2]是删除重复的留一个，这个题是有重复的全删除。  
**方法一：**  
可以while遍历链表，内层再嵌套一个while，有重复就删除当前节点后继节点，最后剩下的当前节点也要删除，可以在内层while中bool一个变量，结束while后通过`if(flag)`和前驱节点，将当前节点删除，考虑边界情况，可先new一个哨兵节点指向head节点

    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) 
        {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *curr = head;
            ListNode *prev = dummy;

            while(curr != NULL)
            {
                bool flag = false;
                while(curr->next != NULL && curr->val == curr->next->val)
                {
                    flag = true;
                    curr->next = curr->next->next;
                }
                if(flag)
                {
                    prev->next = curr->next;
                    curr = curr->next;
                    continue;
                }
                prev = curr;
                curr = curr->next;       
            }
            return dummy->next;
        }
    };

**方法二（迭代）：**  
跟方法一很类似，就是内层while不删除节点，只是`curr = curr->next`，if中也类似，if后面需要更改一点  

    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) 
        {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *curr = head;
            ListNode *prev = dummy;

            while(curr != NULL)
            {
                bool flag = false;
                while(curr->next != NULL && curr->val == curr->next->val)
                {
                    flag = true;
                    curr = curr->next;
                }
                if(flag)
                {	          
                    curr = curr->next;
                    continue;
                }
                prev->next = curr;
                prev = prev->next;
                curr = curr->next;       
            }
            prev->next = curr;
            return dummy->next;
        }
    };

**方法三（递归）：**  

	class Solution 
	{
	public:
	    ListNode* deleteDuplicates(ListNode* head) 
	    {
	        if (head == null || head->next == null) 
			    	  return head;
          ListNode *p = head->next;
          if (head->val == p->val) 
          {
              while (p != NULL && head->val == p->val) 
                  p = p.next;	
              return deleteDuplicates(p);
          }
          else 
          {
              head->next = deleteDuplicates(head->next);
              return head;
          }
	    }
	};
  
  [1]:https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
  [2]:https://github.com/mytlx/LeetCode/tree/master/002.Remove%20Duplicates%20from%20Sorted%20List
