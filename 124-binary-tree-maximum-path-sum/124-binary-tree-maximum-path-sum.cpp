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
         int MaxpathSum(TreeNode* root, int & maxi ){
             if(root==NULL)return 0;
             int leftsum=max(0, MaxpathSum(root->left, maxi));
             int rightsum=max(0,MaxpathSum(root->right, maxi));
             maxi=max(maxi, leftsum+rightsum+ root->val);
             
             return root->val + max(leftsum, rightsum);
             
         }
    
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        MaxpathSum( root, maxi);
        return maxi;
    }
};