/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
      queue<TreeNode*>q;
        q.push(root);
        set<int>st;
        st.insert(root->val);
        while(!q.empty()){
           TreeNode*  cur=q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                    st.insert(cur->left->val);
            }
            if(cur->right){
                q.push(cur->right);
                 //if((st.find(cur->right->val))!=st.end())
                    st.insert(cur->right->val);
            }
            
        }
        if(st.size()>1)return false;
        else return true;
    }
};