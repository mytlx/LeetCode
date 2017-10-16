/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode* curr = NULL;
    struct ListNode* prev = head;
    
    while(prev != NULL)
    {
        if(prev == head)
            curr = prev->next;
        if(curr != NULL)
        {
            if(prev->val == curr->val)
            {
                    prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        else
            break;
    }
    return head;
}
