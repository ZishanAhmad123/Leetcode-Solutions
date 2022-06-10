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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
         if(root==NULL) return ans;
        q.push(root);
        while(!q.empty()){
             vector<int>v;
            int size=q.size();
            
            for(int i=0; i<size; i++){
            TreeNode* cur =q.front();
              q.pop();
            v.push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right)
                q.push(cur->right);
        }
         ans.push_back(v);
        v.clear();
       }  
        return ans;
    }
};