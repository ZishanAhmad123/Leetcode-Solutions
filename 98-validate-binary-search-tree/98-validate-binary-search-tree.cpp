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
    bool checkbst(TreeNode* root, long mini, long maxi){
        if(root==NULL)return true;
        if(root->val <=mini || root->val>=maxi)return false;
        
        return checkbst(root->left, mini, root->val) && checkbst(root->right, root->val, maxi);
           }
    
    bool isValidBST(TreeNode* root) {
        if(checkbst(root, LONG_MIN, LONG_MAX)){
            return true;
        }
        else return false;
       
    }
};