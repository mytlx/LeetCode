# Odd Even Linked List
> Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.  
> 
> You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
>
> **Example:**  
> Given `1->2->3->4->5->NULL`,  
> return `1->3->5->2->4->NULL`.
>
> **Note:**  
> The relative order inside both the even and odd groups should remain as it was in the input.   
> The first node is considered odd, the second node even and so on ...

这道题跟刚刚做的**Partition List**几乎一模一样，创建两个空链表，遍历链表，将奇数节点放在`odd_dummy`，将偶数节点放在`even_dummy`，最后将两个链表连在一起即可。  
中间遇到一些错误提示：  

- `stray '\357' in program` &nbsp;&nbsp;字符编码问题，大概率是**全半角**问题

- `for(ListNode *p = head, int i = 1; p != NULL; p = p->next, i++)`&nbsp;&nbsp;for循环中的表达式1是可以有两个变量的，但是一直报错，无奈只能将`int i = 1`放到外侧

 
