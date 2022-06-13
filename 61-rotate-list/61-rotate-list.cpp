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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode* temp=head;
        ListNode* temp2=head;
        
            int n=0;
            while(temp->next){
                n++;
                temp=temp->next;
            }
        temp->next=head;
          k=k%(n+1);
        
          n=n-k;
        while(n--){
            temp2=temp2->next;
        }
        
      ListNode* cur= temp2->next;           // return pointer 
        temp2->next=NULL;
        
        return cur;
    }
};