# [Merge k Sorted Lists][1]
> Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

这道题很多种解法，现在只研究了一种，[**分治法**][2]，二分循环merge两个,不用递归

	ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        size_t n = lists.size();
        if(n == 0) return NULL;
        
        while(n > 1)
        {
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; i++)
               lists[i] =  mergeTwoLists(lists[i], lists[i + k]);
            n = k;
        }
        return lists[0];    
    }
中间需要用到[**Merge Two Sorted Lists**][3]

	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 == NULL) p->next = l2;
        else if(l2 == NULL) p->next = l1;
        return dummy->next;
	}


[1]:https://leetcode.com/problems/merge-k-sorted-lists/description/
[2]:https://baike.baidu.com/item/%E5%88%86%E6%B2%BB%E6%B3%95/2407337?fr=aladdin
[3]:https://github.com/mytlx/LeetCode/tree/master/001.Merge%20Two%20Sorted%20Lists
