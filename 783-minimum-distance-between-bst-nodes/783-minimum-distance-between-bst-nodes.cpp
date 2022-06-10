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
    int mini=1e9;
    int prev=-1 ;
    void  inorder(TreeNode* root){
        if(root==NULL)return ;
        inorder(root->left);

        if(prev==-1)prev=root->val;
        else
          mini=min(mini, (root->val-prev));
        prev=root->val;
        
        inorder(root->right);
         
    }
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)return 0;
        
        inorder(root);
        return mini;
    }
};