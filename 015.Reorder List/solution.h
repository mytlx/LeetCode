/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) return;
        ListNode *fast = head, *slow = head, *prev = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;  //截断链表
        slow = reverse(slow);
        
        ListNode *curr = head;
        ListNode *tmp = NULL;
        while(curr->next != NULL)
        {
            tmp = curr->next;
            curr->next = slow;
            slow = slow->next;
            curr->next->next = tmp;
            curr = tmp;
        }
        curr->next = slow;
    }
    
    ListNode *reverse(ListNode* head)
    {
        ListNode *prev = NULL, *curr = head, *succ = NULL;
        while(curr != NULL)
        {
            succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
        }
        return prev;
    }
};
