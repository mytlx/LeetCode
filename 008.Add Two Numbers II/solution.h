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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> s1, s2, s;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!s1.empty() || !s2.empty())
        {
            int sum = 0;
            if(!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            sum += carry;
            s.push(sum % 10);
            carry = sum / 10;
        }
        if(carry)
            s.push(carry); 
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        while(!s.empty())
        {         
            curr->next = new ListNode(s.top());
            curr = curr->next;
            s.pop();
        }
        return dummyHead->next;      
    }
};
