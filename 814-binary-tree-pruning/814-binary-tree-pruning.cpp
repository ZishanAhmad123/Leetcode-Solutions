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
int abc(TreeNode* root){
    if(root==NULL) return 0;
    int a = abc(root->left);
    int b = abc(root->right);
    if(a==0) root->left=NULL;
    if(b==0) root->right=NULL;
    return a+b+root->val;
}
TreeNode* pruneTree(TreeNode* root) {
    int x=abc(root);
    if(x==0) return NULL;
    return root;
}
};