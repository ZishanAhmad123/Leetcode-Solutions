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
    	int findHeight(TreeNode *root){
    if (root == NULL)
        return 0;

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    return max(lh, rh) + 1;
}
    void f(TreeNode* root, int &sum, int height ){
      if(!root)return ;
        if(height==1)
            sum+=root->val;
        f(root->left, sum ,height-1);
        f(root->right, sum , height-1);
    }

    
    int deepestLeavesSum(TreeNode* root) {
       int sum=0;
        if(root==NULL)return 0;
        
        int height=findHeight(root);
        f(root, sum, height);
        return sum;
        
    }
};