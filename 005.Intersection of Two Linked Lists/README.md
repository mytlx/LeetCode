# Intersection of Two Linked Lists
> Write a program to find the node at which the intersection of two singly linked lists begins.  
> For example, the following two linked lists:  
>
	A:          a1 → a2
	                   ↘
	                     c1 → c2 → c3
	                   ↗            
	B:     b1 → b2 → b3
> begin to intersect at node c1.
> begin to intersect at node c1.  
>
> **Notes**:
> 
> - If the two linked lists have no intersection at all, return `null`.
> - The linked lists must retain their original structure after the function returns.
> - You may assume there are no cycles anywhere in the entire linked structure.
> - Your code should preferably run in O(n) time and use only O(1) memory.

看到这个题，感觉挺简单的，声明两个指针各指向一个list，之后循环遍历判断指针是否相等，要注意一些特殊情况，比如：`空表，[1] [1]`等

