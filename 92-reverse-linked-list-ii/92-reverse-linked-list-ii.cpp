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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head == NULL ) return head; 
       if(right==left)
           return head;
       
         ListNode * p = new ListNode();
         p->next = head;   // make p as a previous node of head;
       
        ListNode * leftPos = p;
        ListNode * rightPos = p;

// step 1 : find the (left-1)th  node 
      int i=0, j=0;
      while(i<left-1){
          i++;
          leftPos = leftPos->next;
      }
// step 2 : find the (right)th node        
        while(j<right){
             rightPos = rightPos->next;
            j++;
        }
       
        ListNode * cur = leftPos->next;

        leftPos->next = rightPos; // connecting (left-1)th node to (right)th node
        
        ListNode * temp = rightPos->next;
        ListNode * temp2 = rightPos->next;
        while (cur != temp2){
            ListNode * next = cur->next;
            cur->next = temp;
            temp = cur;
            cur = next;
        }
        return p->next;
        
    }
};