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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> s;
        for(auto i:nums) s.insert(i);
        ListNode* temp=head;
        while(temp->next!=NULL and temp!=NULL){
            //if the value next to temp pointer is  present in set than it forms a connected component
            if(s.find(temp->next->val)!=s.end()){
                //removing current node from set so that only one node from each connected component will
                //be present in set
                s.erase(temp->val);
            }
            temp=temp->next;
        }
        return s.size();
    }
};