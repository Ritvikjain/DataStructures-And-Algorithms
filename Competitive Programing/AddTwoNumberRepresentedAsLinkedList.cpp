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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode *temp,*prev;
        int carry = 0,sum = 0;
        while(l1 != NULL || l2 != NULL)
        {
            sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            
            carry = (sum >= 10 ? 1 : 0);
            sum = sum%10;
            temp = new ListNode(sum);
            if(res == NULL)
            {
                res = temp;
            }else{
                prev->next = temp; 
            }
            prev = temp;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry > 0)
        {
            prev->next = new ListNode(carry);
        }
        return res;
    }
};
