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
     void f(TreeNode* root, int &diff, TreeNode* &prev)
    {
        if(!root) return;
        
        f(root->left, diff, prev);
        if (prev) diff = min(diff, abs(prev->val - root->val));
        prev = root;
        f(root->right, diff, prev);
    }
    
    int getMinimumDifference(TreeNode* root) {
         int diff=1e9;
        TreeNode* prev = NULL;
        
        f(root, diff, prev);
        return diff;
    }
};