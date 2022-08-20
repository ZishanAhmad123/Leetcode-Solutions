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
    void inorder(TreeNode* root, vector<int>&v1){
        if(root==NULL)return ;
        inorder(root -> left, v1);
        
        v1.push_back(root -> val);
        
        inorder(root -> right, v1);
        
    }
  TreeNode* balance_bst( vector<int>&arr,int start, int end){
       if(start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root -> left = balance_bst(arr, start, mid - 1);
        root -> right = balance_bst(arr, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v1;
       inorder(root,v1);
        int s=0, e=v1.size()-1;
        return balance_bst(v1, s, e);
    }
};