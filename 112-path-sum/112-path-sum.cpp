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
       bool ans=false;
    vector<int>v;
    void f(TreeNode* root, int sum, int tsum){
        if(!root)return ;
       
        v.push_back(root->val);
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==tsum){
                ans=true;
            return;}
        }
        f(root->left, sum, tsum);
        f(root->right, sum, tsum);
       
    }
    
    bool hasPathSum(TreeNode* root, int tsum) {
        int sum=0;
         f(root, sum, tsum);
        return ans;
    }
};