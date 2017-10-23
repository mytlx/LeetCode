/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(head == NULL)
            return NULL;
        RandomListNode *p = head;
        while(p != NULL)
        {
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while(p != NULL)
        {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        RandomListNode *q = head->next;
        RandomListNode *qHead = q;
        while(q->next != NULL)
        {
            p->next = q->next;
            p = p->next;
            q->next = p->next;
            q = q->next;
        }
        p->next = NULL;
        q->next = NULL;
        return qHead;
    }
};
