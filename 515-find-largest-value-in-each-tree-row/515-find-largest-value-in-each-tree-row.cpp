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
    vector<int> largestValues(TreeNode* root) {
         int level = 1;
       vector<int>v;
         if(root==NULL){
            return {};
        }
        //int maxi=-1e9;
        queue<TreeNode*> q;
        q.push(root);
       
        while(q.empty() != true){
            int width = q.size();
            int maxi=INT_MIN;
            for(int i = 0 ; i < width ; i++){
                
                TreeNode* curr = q.front();
                q.pop();
                
              if(curr->val>maxi){
                 maxi=curr->val;
              }
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }                                       
            }
            v.push_back(maxi);
        }
        
       return v;
    }
};