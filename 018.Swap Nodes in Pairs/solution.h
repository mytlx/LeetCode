/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        ListNode *succ = head->next;
        
        while(succ)
        {
            //交换节点
            prev->next = succ;
            curr->next = succ->next;
            succ->next = curr;
            //每个往后走两步
            prev = curr;
            curr = curr->next;
            succ = curr != NULL? curr->next : NULL;
        }
        return dummy->next;
    }
};
