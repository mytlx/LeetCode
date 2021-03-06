# Linked List Cycle II
> Given a linked list, return the node where the cycle begins. If there is no cycle, return null.  
> 
> **Note:** Do not modify the linked list.  
> 
> **Follow up:**
Can you solve it without using extra space?

这道题和**Linked List Cycle**很像，都是快慢指针的用法，找进入圆环的起始节点，需要一些公式推导。  
![](https://i.imgur.com/bzUCGLx.png)  

当slow和fast相遇时，slow肯定没走完，而fast已经循环了n圈（n >= 1），假设slow走了s步，fast走了ts步（t为整数），设环长为r，则：

`ts = s + nr`

`(t-1)s = nr`

设整个链表长度为L，环入口点与相遇点距离为a，起点到环入口点距离为x，则：

`x + a = s = n / (t-1) * r = [(n / (t-1) - 1] * r + r = [(n / (t-1) - 1] * r + L - x`

`x = [(n / (t-1) - 1] * r + L - x - a`

所以，要保证`[(n / (t-1) - 1]`恒为整数， `t = 2`，所以fast每次走两步。由上式可知，如果此时新定义一个slow2指针指向head，当slow2走到入口点（x点）时，slow也一定走到入口点（`循环几圈 + L-x-a`），由此可求出入口点节点。
