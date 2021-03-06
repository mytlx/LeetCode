# Partition List
> Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.  
> 
> You should preserve the original relative order of the nodes in each of the two partitions.  
> 
> For example,  
> Given `1->4->3->2->5->2` and x = 3,  
> return `1->2->2->4->3->5`.

最开始的想法是，用两个指针，一个指在第一个大于等于x的前一个节点，另一个去寻找小于x的节点，然后将寻找的的节点置于第一个指针后，
考虑头结点的情况，需要声明一个哨兵节点指向头结点。  
后来看了眼答案，声明两个哨兵节点，一个`left_dummy`,一个`right_dummy`,将小于x的节点链在`left_dummy`后，将大于等于x的节点链在`right_dummy`后，
最后将两个节点组合。
