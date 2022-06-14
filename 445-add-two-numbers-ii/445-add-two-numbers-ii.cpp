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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          l1 = reverse(l1);
          l2 = reverse(l2);
        
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        
        int carry = 0;
        
        while(l1 or l2){
            
            int sum = 0;
            
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            
            temp->next = new ListNode(sum);
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
            temp = temp->next;
        }
        
         if(carry!=0){
            temp->next = new ListNode(carry);
        }
        
        head = reverse(head->next);
        
        return head;     
    }
};