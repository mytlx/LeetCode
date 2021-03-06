# Merge Two Sorted Lists
> Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

维护两个指针对应两个链表（从小到大排列），因为一般会以一条链表为基准，比如说l1, 那么如果l1当期那的元素比较小，那么直接移动l1即可，否则将l2当前的元素插入到l1当前元素的前面。  

算法时间复杂度是O(m+n),m和n分别是两条链表的长度，空间复杂度是O(1)。

如下图

![](https://i.imgur.com/jI2IpoY.png)

代码如下

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

判断一下余下的l2链表是否为空，如果不为空，则加到已排好链表尾部即可

	if(l2 != NULL)
        pnew->next = l2;
