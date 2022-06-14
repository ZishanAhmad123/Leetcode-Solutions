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
  ListNode*   stacktolist(stack<int>s){
        ListNode* head=NULL;
        ListNode* temp=NULL;
      while(s.size()){
          int a =s.top();
          s.pop();
          ListNode* node= new ListNode(a);
          
          if(head==NULL){
              head=node;
              temp=node;
          }
          else{
              temp->next=node;
              temp=temp->next;
          }
      }
      return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          stack<int>s1;
          stack<int>s2, ans;
        int carry=0;
     
         while(l1!=NULL)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
    
        while(!s1.empty() and !s2.empty()){
            int a=s1.top();int b=s2.top();
            s1.pop();s2.pop();
            int sum=a+b+carry;
            carry=sum/10;
            ans.push(sum%10);
        }
        while(s1.size()){
             int sum=s1.top()+carry;
            s1.pop();
            ans.push(sum%10);
            carry=sum/10;
        }
        while(s2.size()){
             int sum=s2.top()+carry;
            s2.pop();
            ans.push(sum%10);
            carry=sum/10;
        }
        if(carry!=0){
            ans.push(carry);
        }
        
        return stacktolist(ans);    
    }
};