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
// class Solution {
// public: 
//     int mini=1e9;
//     int prev=-1 ;
//     void  inorder(TreeNode* root){
//         if(root==NULL)return ;
//         inorder(root->left);

//         if(prev==-1)prev=root->val;
//         else
//           mini=min(mini, (root->val-prev));
//         prev=root->val;
        
//         inorder(root->right);
         
//     }
//     int minDiffInBST(TreeNode* root) {
//         if(root==NULL)return 0;
        
//         inorder(root);
//         return mini;
//     }
// };

class Solution {
 public: 
   void inorder(TreeNode* root, vector<int>&v){
       if(root==NULL)return ;
       inorder(root->left, v);
       v.push_back(root->val);
       inorder(root->right,v);
   }
     int minDiffInBST(TreeNode* root) {
        if(root==NULL)return 0;
         vector<int>v;
        inorder(root, v);
           int ans=1e9;;
         for(int i=1; i<size(v); i++){
             ans=min(ans, (v[i]-v[i-1]));
         }
        return ans; 
     }
};