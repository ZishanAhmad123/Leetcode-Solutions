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
       TreeNode* insert( TreeNode* root, int data){
    if (root == nullptr) {
        return   new  TreeNode(data);
    }
    if (data < root->val) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;}
    
   TreeNode*  sortedbst(vector<int>nums, int start, int end){
       if(start>end)return NULL;
       int mid=(start+end)/2;
       TreeNode* root=  new  TreeNode(nums[mid]);
       root->left=sortedbst(nums, start, mid-1);
       root->right=sortedbst(nums, mid+1, end);
       
       return root;
   }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       TreeNode* root= sortedbst(nums, 0, size(nums)-1); 
        return root;
    }
};