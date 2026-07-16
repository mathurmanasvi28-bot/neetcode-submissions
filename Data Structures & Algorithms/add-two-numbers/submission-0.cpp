/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int carry = 0;
        while(l1 != NULL || l2!=NULL || carry){
            int val1 = 0;
            int val2 = 0;
            if(l1 != NULL){
                val1 = l1->val;
            }else{
                val1 = 0;
            }
            if(l2 != NULL){
                val2 = l2->val;
            }else{
                val2 = 0;
            }
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* value = new ListNode(digit);
            curr->next = value;
            curr = curr->next;
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2!=NULL){
                l2 = l2->next;
            }
        }
        return ans->next;
    }
};
