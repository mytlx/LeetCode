# Add Two Numbers II
> You are given two **non-empty** linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.  
> 
> You may assume the two numbers do not contain any leading zero, except the number 0 itself.
>
> **Follow up:**  
> What if you cannot modify the input lists? In other words, reversing the lists is not allowed.  
> 
> **Example:**  
> Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)  
> Output: 7 -> 8 -> 0 -> 7

这道题跟**Add Two Numbers**区别就是这道题是正序保存的，难点就是需要从最后一位往前相加，
由于不允许reverse链表，而且没要求空间大小，所以可以考虑用stack来实现，建三个stack，一个保存输出，
另两个保存输入，最后将输出的保存到新链表，新链表即是正序保存的。
