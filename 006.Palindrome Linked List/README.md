# Palindrome Linked List
> Given a singly linked list, determine if it is a palindrome.  
>   
> **Follow up:**  
> Could you do it in O(n) time and O(1) space?

回文链表，首先要找中间元素，可用快慢指针法寻找，声明fast和slow一快一慢指针，fast每次移动**两个**单位，
slow每次移动**一个**单位，当fast移动到末尾时，slow指向的便是中间元素。  

	ListNode* fast = head;
	ListNode* slow = head;
	while(fast->next && fast->next->next)
	{
	    fast = fast->next->next;
	    slow = slow->next;
	}

下一步要做的是比较元素值是否相等：  

**第一种**方法可用栈实现，寻找中间元素时，slow每走一步一个元素入栈，slow走到中间时，前半部分元素都已入栈，	由栈**先进后出**的性质，
可与后面回文链表比较了。  

	class Solution
	{
	public:
	    bool isPalindrome(ListNode* head) 
		{
	        if (!head || !head->next) 
				return true;
	        ListNode *slow = head, *fast = head;
	        stack<int> s;
	        s.push(head->val);
	        while (fast->next && fast->next->next) 
			{
	            slow = slow->next;
	            fast = fast->next->next;
	            s.push(slow->val);
	        }
	        if (!fast->next) s.pop();
	        while (slow->next) 
			{
	            slow = slow->next;
	            int tmp = s.top(); 
				s.pop();
	            if (tmp != slow->val) 
					return false;
	        }
	        return true;
	    }
	}; 

**第二种**方法：由于题目要求使用O(1)的空间，所以不能使用栈，为了倒着取元素，可从链表中点翻转链表，按照回文格式比较。  
![](https://i.imgur.com/838f64m.png)

	ListNode* last = slow->next;
	ListNode* prev = head;
	while(last->next)
	{
	    ListNode* temp = last->next;
	    last->next = temp->next;
	    temp->next = slow->next;
	    slow->next = temp;
	}
