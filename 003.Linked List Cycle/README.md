# Linked List Cycle
> Given a linked list, determine if it has a cycle in it.  
> Follow up:  Can you solve it without using extra space?

看到这个题，我的第一想法是检查list中是否存在NULL即可，想了想发现如果用循环检查，是cycle的话会变成一个死循环，
看了一下提示突然反应过来可以用两个pointer，一个快，一个慢，就像两个不同速度的人在圆形操场跑圈，总有两个人相遇的时候，即被扣圈，
为了实现扣圈相遇，fast一定要跑在slow前面。
  
    bool hasCycle(struct ListNode *head) 
    {       
      if(head == NULL || head->next == NULL)
          return false;
      struct ListNode* slow = head;
      struct ListNode* fast = head->next; 
      while(slow != fast)
      {
          if(fast == NULL || fast->next == NULL)
              return false;
          slow = slow->next;
          fast = fast->next->next;
      }
      return true;
    }
