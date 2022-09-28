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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        int numNodes = 0;
        ListNode *temp = head;
        while(temp != NULL) {
            numNodes++;
            temp = temp->next;
        }  
    
        if(numNodes == n) {
            return head->next;
        }
        
        temp = head;
        for(int i = 0; i < numNodes-1-n; ++i, temp = temp->next);
        temp->next = temp->next->next;
        
        return head;
    }
};