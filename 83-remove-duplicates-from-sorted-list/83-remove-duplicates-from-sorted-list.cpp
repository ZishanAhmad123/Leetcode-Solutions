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
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode *cur = head;
            ListNode *prev = NULL;
            unordered_set<int> st;
            while (cur)
            {
                if (st.find(cur->val) != st.end())
                {
                    prev->next = cur->next;
                    delete(cur);
                    cur = prev->next;
                }
                else
                {
                    st.insert(cur->val);
                    prev = cur;
                    cur = prev->next;
                }
            }
            return head;
    }
};