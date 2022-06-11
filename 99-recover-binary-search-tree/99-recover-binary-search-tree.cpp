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
TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prev = NULL;
    void INORDER(TreeNode* root){
     if(root==NULL)return;
    
    INORDER(root->left);
     // Start of "do some business", 
     // If first element has not been found, assign it to prevElement  (6 as in eg 1st)
    if(first==NULL and prev!=NULL and prev->val>=root->val){
        first = prev;   
    }
    // If first element is found, assign the second element to the root (refer to 2 in the example above)
    if(first!=NULL and prev->val>=root->val){
        second = root;
    }
    prev = root;
    INORDER(root->right);
    }
    
    void recoverTree(TreeNode* root) {
         if(!root){
        return;
    }
    INORDER(root);
   swap(first->val, second->val);
    }
};