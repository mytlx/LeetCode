# Copy List with Random Pointer
> A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.  
> Return a deep copy of the list.

深拷贝一个链表，每个节点有个random指针指向任意节点或者NULL，原链表大致如下图，粗线表示random指向，细线表示next指向。

![](https://i.imgur.com/Pr1TxnR.jpg)

深拷贝这个链表很简单，难点在如何拷贝random，构建新节点时，把新节点插到对应原节点后面，如下图
![](https://i.imgur.com/l52xUCz.jpg)  
随后构建新节点指针指向  
	
	p->next->random = p->random->next;
	p = p->next->next;
最后拆分链表
  
	p->next = q->next;
    p = p->next;
    q->next = p->next;
    q = q->next;
