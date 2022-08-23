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
    bool isPalindrome(ListNode* head) {
          ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
      ListNode* cur=slow;
         ListNode* pre=NULL;
         ListNode* next;
        while(cur!=NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
      ListNode* first=head;
        while(pre!=NULL){
            if(first->val!=pre->val)
                return false;
            first=first->next;
            pre=pre->next;
        }
        return true;
    }
};